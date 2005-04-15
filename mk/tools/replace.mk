# $NetBSD: replace.mk,v 1.3 2005/04/15 16:01:23 jlam Exp $
#
# This Makefile fragment handles "replacements" of system-supplied tools
# with pkgsrc versions.  The replacements are placed under ${TOOLS_DIR}
# so that they appear earlier in the search path when invoked using the
# bare name of the tool.
#
# The tools that could be replaced with pkgsrc counterparts (usually
# GNU versions of the tools) should be listed in each package Makefile
# as:
#
#	USE_TOOLS+=	awk gmake lex
#
# If a package requires yacc to generate a parser, then the package
# Makefile should contain one of the following two lines:
#
#	USE_TOOLS+=	yacc	# any yacc will do
#	USE_TOOLS+=	bison	# requires bison-specific features
#
# Adding either "yacc" or "bison" to USE_TOOLS will cause a "yacc" tool
# to be generated that may be used as a yacc-replacement.
#
# By default, any dependencies on the pkgsrc tools are build dependencies,
# but this may be changed by explicitly setting TOOLS_DEPENDS.<tool>,
# e.g.:
#
#	TOOLS_DEPENDS.tbl=	DEPENDS
#

# Continue to allow USE_GNU_TOOLS and USE_TBL until packages have been
# taught to use the new syntax.
#
.for _t_ in ${USE_GNU_TOOLS}
.  if "${_t_}" == "make"
USE_TOOLS+=	gmake
.  else
USE_TOOLS+=	${_t_}
.  endif
.endfor
.if defined(USE_TBL) && !empty(USE_TBL:M[yY][eE][sS])
USE_TOOLS+=	tbl
.endif

.if defined(USE_PERL5)
USE_TOOLS+=	perl
.endif

# Only allow one of "bison" and "yacc".
.if !empty(USE_TOOLS:Mbison) && !empty(USE_TOOLS:Myacc)
PKG_FAIL_REASON+=	"\`\`bison'' and \`\`yacc'' conflict in USE_TOOLS."
.endif

# This is an exhaustive list of tools for which we have pkgsrc
# replacements.
#
_TOOLS_REPLACE_LIST=	awk bison egrep fgrep file gmake grep lex m4	\
			patch perl sed tbl yacc

# TOOL variable names associated with each of the tools
_TOOLS_VARNAME.awk=	AWK
_TOOLS_VARNAME.bison=	YACC
_TOOLS_VARNAME.egrep=	EGREP
_TOOLS_VARNAME.fgrep=	FGREP
_TOOLS_VARNAME.file=	FILE_CMD
_TOOLS_VARNAME.gmake=	GMAKE
_TOOLS_VARNAME.grep=	GREP
_TOOLS_VARNAME.lex=	LEX
_TOOLS_VARNAME.m4=	M4
_TOOLS_VARNAME.patch=	PATCH
_TOOLS_VARNAME.perl=	PERL5
_TOOLS_VARNAME.sed=	SED
_TOOLS_VARNAME.tbl=	TBL
_TOOLS_VARNAME.yacc=	YACC

######################################################################

# For each tool, _TOOLS_USE_PLATFORM.<tool> is a list of platforms for
# which we will use the system-supplied tool instead of the pkgsrc
# version.
#
# This table should probably be split amongst the various mk/platform
# files as they are ${OPSYS}-specific.
#
_TOOLS_USE_PLATFORM.awk=	FreeBSD-*-* Linux-*-* OpenBSD-*-*	\
				NetBSD-1.[0-6]*-* DragonFly-*-*		\
				SunOS-*-* Interix-*-*
_TOOLS_USE_PLATFORM.bison=	Linux-*-*
_TOOLS_USE_PLATFORM.egrep=	Darwin-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-* DragonFly-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.fgrep=	Darwin-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-* DragonFly-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.file=	Darwin-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-* DragonFly-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.gmake=	Darwin-*-*
_TOOLS_USE_PLATFORM.grep=	Darwin-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-* DragonFly-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.lex=	FreeBSD-*-* Linux-*-* NetBSD-*-*	\
				OpenBSD-*-* DragonFly-*-*
_TOOLS_USE_PLATFORM.m4=		# empty
_TOOLS_USE_PLATFORM.patch=	Darwin-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-* DragonFly-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.perl=	# This should always be empty.
_TOOLS_USE_PLATFORM.sed=	FreeBSD-*-* Linux-*-* NetBSD-*-*	\
				DragonFly-*-* SunOS-*-* Interix-*-*
_TOOLS_USE_PLATFORM.tbl=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-*	\
				DragonFly-*-*
_TOOLS_USE_PLATFORM.yacc=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-*	\
				DragonFly-*-*

######################################################################

# _TOOLS_USE_PKGSRC.<prog> is "yes" or "no" depending on whether we're
# using a pkgsrc-supplied tool to replace the system-supplied one.
#
# This currently uses ${OPSYS}-based checking and ignores the scenario
# where your kernel and userland aren't in sync.  This should be turned
# into a bunch of feature tests in the future.
#
.for _t_ in ${_TOOLS_REPLACE_LIST}
.  for _pattern_ in ${_TOOLS_USE_PLATFORM.${_t_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_USE_PKGSRC.${_t_}?=	no
.    endif
.  endfor
.  undef _pattern_
_TOOLS_USE_PKGSRC.${_t_}?=	yes
.endfor
.undef _t_

# TOOLS_DEPENDS.<prog> defaults to BUILD_DEPENDS.
.for _t_ in ${_TOOLS_REPLACE_LIST}
TOOLS_DEPENDS.${_t_}?=	BUILD_DEPENDS
.endfor
.undef _t_

######################################################################

# For each of the blocks below, we create either symlinks or wrappers
# for each of the tools requested.  We need to be careful that we don't
# get into dependency loops; do this by setting and checking the value
# of TOOLS_IGNORE.<tool>.  If we're using the system-supplied tool, we
# defer the setting of TOOLS_REAL_CMD.<tool> until the loop at the end.
#
.if !defined(TOOLS_IGNORE.awk) && !empty(USE_TOOLS:Mawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.awk=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.awk:M[yY][eE][sS])
${TOOLS_DEPENDS.awk}+=		gawk>=3.1.1:../../lang/gawk
TOOLS_REAL_CMD.awk=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
${_TOOLS_VARNAME.awk}=		${TOOLS_REAL_CMD.awk}
.    endif
TOOLS_SYMLINK+=			awk
TOOLS_CMD.awk=			${TOOLS_DIR}/bin/awk
.  endif
.endif

.if !defined(TOOLS_IGNORE.bison) && !empty(USE_TOOLS:Mbison)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.bison:M[yY][eE][sS])
${TOOLS_DEPENDS.bison}+=	bison>=1.0:../../devel/bison
TOOLS_REAL_CMD.bison=		${LOCALBASE}/bin/bison
.    endif
TOOLS_WRAP+=			bison
TOOLS_CMD.bison=		${TOOLS_DIR}/bin/yacc
TOOLS_ARGS.bison=		-y
${_TOOLS_VARNAME.bison}=	${TOOLS_REAL_CMD.bison} ${TOOLS_ARGS.bison}
.  endif
.endif

.if !defined(TOOLS_IGNORE.egrep) && !empty(USE_TOOLS:Megrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.egrep=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.egrep:M[yY][eE][sS])
${TOOLS_DEPENDS.egrep}+=	grep>=2.5.1:../../textproc/grep
TOOLS_REAL_CMD.egrep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}egrep
${_TOOLS_VARNAME.egrep}=	${TOOLS_REAL_CMD.egrep}
.    endif
TOOLS_SYMLINK+=			egrep
TOOLS_CMD.egrep=		${TOOLS_DIR}/bin/egrep
.  endif
.endif

.if !defined(TOOLS_IGNORE.fgrep) && !empty(USE_TOOLS:Mfgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.fgrep=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.fgrep:M[yY][eE][sS])
${TOOLS_DEPENDS.fgrep}+=	grep>=2.5.1:../../textproc/grep
TOOLS_REAL_CMD.fgrep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}fgrep
${_TOOLS_VARNAME.fgrep}=	${TOOLS_REAL_CMD.fgrep}
.    endif
TOOLS_SYMLINK+=			fgrep
TOOLS_CMD.fgrep=		${TOOLS_DIR}/bin/fgrep
.  endif
.endif

.if !defined(TOOLS_IGNORE.file) && !empty(USE_TOOLS:Mfile)
.  if !empty(PKGPATH:Msysutils/file)
MAKEFLAGS+=			TOOLS_IGNORE.file=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.file:M[yY][eE][sS])
${TOOLS_DEPENDS.file}+=		file>=4.13:../../sysutils/file
TOOLS_REAL_CMD.file=		${LOCALBASE}/bin/file
${_TOOLS_VARNAME.file}=	${TOOLS_REAL_CMD.file}
.    endif
TOOLS_SYMLINK+=			file
TOOLS_CMD.file=			${TOOLS_DIR}/bin/file
.  endif
.endif

.if !defined(TOOLS_IGNORE.gmake) && !empty(USE_TOOLS:Mgmake)
.  if !empty(PKGPATH:Mdevel/gmake)
MAKEFLAGS+=			TOOLS_IGNORE.gmake=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.gmake:M[yY][eE][sS])
${TOOLS_DEPENDS.gmake}+=	gmake>=3.78:../../devel/gmake
TOOLS_REAL_CMD.gmake=		${LOCALBASE}/bin/gmake
${_TOOLS_VARNAME.gmake}=	${TOOLS_REAL_CMD.gmake}
.    endif
TOOLS_SYMLINK+=			gmake
TOOLS_CMD.gmake=		${TOOLS_DIR}/bin/gmake
.  endif
.endif

.if !defined(TOOLS_IGNORE.grep) && !empty(USE_TOOLS:Mgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.grep=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.grep:M[yY][eE][sS])
${TOOLS_DEPENDS.grep}+=		grep>=2.5.1:../../textproc/grep
TOOLS_REAL_CMD.grep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep
${_TOOLS_VARNAME.grep}=		${TOOLS_REAL_CMD.grep}
.    endif
TOOLS_SYMLINK+=			grep
TOOLS_CMD.grep=			${TOOLS_DIR}/bin/grep
.  endif
.endif

.if !defined(TOOLS_IGNORE.lex) && !empty(USE_TOOLS:Mlex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.lex=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.lex:M[yY][eE][sS])
.      include "../../devel/flex/buildlink3.mk"
TOOLS_REAL_CMD.lex=		${LOCALBASE}/bin/flex
${_TOOLS_VARNAME.lex}=		${TOOLS_REAL_CMD.lex}
.    endif
TOOLS_SYMLINK+=			lex
TOOLS_CMD.lex=			${TOOLS_DIR}/bin/lex
.  endif
.endif

.if !defined(TOOLS_IGNORE.m4) && !empty(USE_TOOLS:Mm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.m4=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.m4:M[yY][eE][sS])
${TOOLS_DEPENDS.m4}+=		m4>=1.4:../../devel/m4
TOOLS_REAL_CMD.m4=		${LOCALBASE}/bin/gm4
${_TOOLS_VARNAME.m4}=		${TOOLS_REAL_CMD.m4}
.    endif
TOOLS_SYMLINK+=			m4
TOOLS_CMD.m4=			${TOOLS_DIR}/bin/m4
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
${TOOLS_DEPENDS.patch}+=	patch>=2.2:../../devel/patch
TOOLS_REAL_CMD.patch=		${LOCALBASE}/bin/gpatch
${_TOOLS_VARNAME.patch}=	${TOOLS_REAL_CMD.patch}
.    endif
TOOLS_SYMLINK+=			patch
TOOLS_CMD.patch=		${TOOLS_DIR}/bin/patch
.  endif
.endif

.if !defined(TOOLS_IGNORE.perl) && !empty(USE_TOOLS:Mperl)
.  if !empty(PKGPATH:Mlang/perl5)
MAKEFLAGS+=			TOOLS_IGNORE.perl=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.perl:M[yY][eE][sS])
.      include "../../lang/perl5/buildlink3.mk"
TOOLS_REAL_CMD.perl=		${LOCALBASE}/bin/perl
${_TOOLS_VARNAME.perl}=		${TOOLS_REAL_CMD.perl}
.    endif
TOOLS_SYMLINK+=			perl
TOOLS_CMD.perl=			${TOOLS_DIR}/bin/perl
.  endif
.endif

.if !defined(TOOLS_IGNORE.sed) && !empty(USE_TOOLS:Msed)
.  if !empty(PKGPATH:Mtextproc/sed)
MAKEFLAGS+=			TOOLS_IGNORE.sed=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.sed:M[yY][eE][sS])
${TOOLS_DEPENDS.sed}+=		gsed>=3.0.2:../../textproc/gsed
TOOLS_REAL_CMD.sed=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed
${_TOOLS_VARNAME.sed}=		${TOOLS_REAL_CMD.sed}
.    endif
TOOLS_SYMLINK+=			sed
TOOLS_CMD.sed=			${TOOLS_DIR}/bin/sed
.  endif
.endif

.if !defined(TOOLS_IGNORE.tbl) && !empty(USE_TOOLS:Mtbl)
.  if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=			TOOLS_IGNORE.tbl=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.tbl:M[yY][eE][sS])
${TOOLS_DEPENDS.tbl}+=		groff>=1.19nb4:../../textproc/groff
TOOLS_REAL_CMD.tbl=		${LOCALBASE}/bin/tbl
${_TOOLS_VARNAME.tbl}=		${TOOLS_REAL_CMD.tbl}
.    endif
TOOLS_SYMLINK+=			tbl
TOOLS_CMD.tbl=			${TOOLS_DIR}/bin/tbl
.  endif
.endif

.if !defined(TOOLS_IGNORE.yacc) && !empty(USE_TOOLS:Myacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.yacc=
.  else
.    if !empty(_TOOLS_USE_PKGSRC.yacc:M[yY][eE][sS])
${TOOLS_DEPENDS.yacc}+=		bison>=1.0:../../devel/bison
TOOLS_REAL_CMD.yacc=		${LOCALBASE}/bin/bison
TOOLS_ARGS.yacc=		-y
${_TOOLS_VARNAME.yacc}=		${TOOLS_REAL_CMD.yacc} ${TOOLS_ARGS.yacc}
TOOLS_WRAP+=			yacc
.    else
TOOLS_SYMLINK+=			yacc
.    endif
TOOLS_CMD.yacc=			${TOOLS_DIR}/bin/yacc
.  endif
.endif

######################################################################

# Set TOOLS_REAL_CMD.<tool> appropriately in the case where we are
# using the system-supplied tool.  Here, we check to see if TOOL is
# defined.  If it is, then use that as the path to the real command.
# Otherwise, set TOOL to be TOOLS_REAL_CMD.<tool>, which we defer
# until TOOLS_{WRAP,SYMLINK} is processed within bsd.tools.mk.
#
# Also, set the TOOL name for each tool to point to the real command
# in the event that it's not predefined, e.g. TBL, YACC.
#
.for _t_ in ${_TOOLS_REPLACE_LIST}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(USE_TOOLS:M${_t_}) && \
      !empty(_TOOLS_USE_PKGSRC.${_t_}:M[nN][oO])
.    if defined(${_TOOLS_VARNAME.${_t_}})
.      if !empty(${_TOOLS_VARNAME.${_t_}}:M/*)
TOOLS_REAL_CMD.${_t_}?=	\
	${${_TOOLS_VARNAME.${_t_}}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.      endif
.    else
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}}
.    endif
.  endif
.endfor
.undef _t_
