# $NetBSD: replace.mk,v 1.27 2005/04/26 22:28:03 jlam Exp $
#
# This Makefile fragment handles "replacements" of system-supplied
# tools with pkgsrc versions.  The replacements are placed under
# ${TOOLS_DIR} so that they appear earlier in the search path when
# invoked using the bare name of the tool.  Also, any "TOOL" variables,
# e.g. AWK, SED, etc. are set properly to the replacement tool.
#
# The tools that could be replaced with pkgsrc counterparts (usually
# GNU versions of the tools) should be listed in each package Makefile
# as:
#
#	USE_TOOLS+=	gawk gmake lex
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
.if defined(USE_GNU_TOOLS) && !empty(USE_GNU_TOOLS)
USE_TOOLS+=	${USE_GNU_TOOLS:S/^awk$/gawk/:S/^make$/gmake/:S/^sed$/gsed/}
.endif
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
_TOOLS_REPLACE_LIST=	bison egrep fgrep file find gawk gm4 gmake grep	\
			gsed gunzip gzcat gzip lex patch perl tbl xargs	\
			yacc

# "TOOL" variable names associated with each of the tools
_TOOLS_VARNAME.bison=	YACC
_TOOLS_VARNAME.egrep=	EGREP
_TOOLS_VARNAME.fgrep=	FGREP
_TOOLS_VARNAME.file=	FILE_CMD
_TOOLS_VARNAME.find=	FIND
_TOOLS_VARNAME.gawk=	AWK
_TOOLS_VARNAME.gm4=	M4
_TOOLS_VARNAME.gmake=	GMAKE
_TOOLS_VARNAME.grep=	GREP
_TOOLS_VARNAME.gsed=	SED
_TOOLS_VARNAME.gunzip=	GUNZIP_CMD
_TOOLS_VARNAME.gzcat=	GZCAT
_TOOLS_VARNAME.gzip=	GZIP_CMD
_TOOLS_VARNAME.lex=	LEX
_TOOLS_VARNAME.patch=	PATCH
_TOOLS_VARNAME.perl=	PERL5
_TOOLS_VARNAME.tbl=	TBL
_TOOLS_VARNAME.xargs=	XARGS
_TOOLS_VARNAME.yacc=	YACC

######################################################################

# For each tool, _TOOLS_USE_PLATFORM.<tool> is a list of platforms for
# which we will use the system-supplied tool instead of the pkgsrc
# version.
#
# This table should probably be split amongst the various mk/platform
# files as they are ${OPSYS}-specific.
#
_TOOLS_USE_PLATFORM.bison=	Linux-*-*
_TOOLS_USE_PLATFORM.egrep=	${_TOOLS_USE_PLATFORM.grep}
_TOOLS_USE_PLATFORM.fgrep=	${_TOOLS_USE_PLATFORM.grep}
_TOOLS_USE_PLATFORM.file=	Darwin-*-* DragonFly-*-* FreeBSD-*-*	\
				Linux-*-* NetBSD-*-* OpenBSD-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.find=	Linux-*-*
_TOOLS_USE_PLATFORM.gawk=	DragonFly-*-* FreeBSD-*-* Interix-*-*	\
				Linux-*-* NetBSD-1.[0-6]*-* OpenBSD-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.gm4=	# empty
_TOOLS_USE_PLATFORM.gmake=	Darwin-*-*
_TOOLS_USE_PLATFORM.grep=	Darwin-*-* DragonFly-*-* FreeBSD-*-*	\
				Linux-*-* NetBSD-*-* OpenBSD-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.gsed=	Interix-*-* Linux-*-* SunOS-*-*
_TOOLS_USE_PLATFORM.gunzip=	${_TOOLS_USE_PLATFORM.gzip}
_TOOLS_USE_PLATFORM.gzcat=	${_TOOLS_USE_PLATFORM.gzip}
_TOOLS_USE_PLATFORM.gzip=	BSDOS-*-* Darwin-*-* DragonFly-*-*	\
				FreeBSD-*-* IRIX-*-* Interix-*-*	\
				Linux-*-* NetBSD-*-* OSF1-*-*		\
				OpenBSD-*-* SunOS-*-*
_TOOLS_USE_PLATFORM.lex=	DragonFly-*-* FreeBSD-*-* Linux-*-*	\
				NetBSD-*-* OpenBSD-*-*
_TOOLS_USE_PLATFORM.patch=	Darwin-*-* DragonFly-*-* FreeBSD-*-*	\
				Linux-*-* NetBSD-*-* OpenBSD-*-*	\
				SunOS-*-*
_TOOLS_USE_PLATFORM.perl=	# This should always be empty.
_TOOLS_USE_PLATFORM.tbl=	DragonFly-*-* FreeBSD-*-* NetBSD-*-*	\
				OpenBSD-*-*
_TOOLS_USE_PLATFORM.xargs=	${_TOOLS_USE_PLATFORM.find}
_TOOLS_USE_PLATFORM.yacc=	DragonFly-*-* FreeBSD-*-* NetBSD-*-*	\
				OpenBSD-*-*

######################################################################

# _TOOLS_USE_PKGSRC.<tool> is "yes" or "no" depending on whether we're
# using a pkgsrc-supplied tool to replace the system-supplied one.  We
# use the system-supplied one if PLATFORM_TOOL.<tool> is non-empty, or
# otherwise if this is a particular ${MACHINE_PLATFORM} listed above.
#
.for _t_ in ${_TOOLS_REPLACE_LIST}
.  for _pattern_ in ${_TOOLS_USE_PLATFORM.${_t_}}
.    if defined(PLATFORM_TOOL.${_t_}) && !empty(PLATFORM_TOOL.${_t_})
_TOOLS_USE_PKGSRC.${_t_}?=	no
.    endif
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_USE_PKGSRC.${_t_}?=	no
.    endif
.  endfor
.  undef _pattern_
_TOOLS_USE_PKGSRC.${_t_}?=	yes
.endfor
.undef _t_

# TOOLS_DEPENDS.<tool> defaults to BUILD_DEPENDS.
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
.if !defined(TOOLS_IGNORE.bison) && !empty(USE_TOOLS:Mbison)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison=
.  elif !empty(_TOOLS_USE_PKGSRC.bison:M[yY][eE][sS])
${TOOLS_DEPENDS.bison}+=	bison>=1.0:../../devel/bison
TOOLS_WRAP+=			bison
TOOLS_REAL_CMD.bison=		${LOCALBASE}/bin/bison
TOOLS_ARGS.bison=		-y
.    if exists(${TOOLS_REAL_CMD.bison})
${_TOOLS_VARNAME.bison}=	${TOOLS_REAL_CMD.bison} ${TOOLS_ARGS.bison}
.    endif
.  endif
TOOLS_CMD.bison=		${TOOLS_DIR}/bin/yacc
.endif

.if (!defined(TOOLS_IGNORE.egrep) && \
     !defined(TOOLS_IGNORE.fgrep) && \
     !defined(TOOLS_IGNORE.grep)) && \
    (!empty(USE_TOOLS:Megrep) || \
     !empty(USE_TOOLS:Mfgrep) || \
     !empty(USE_TOOLS:Mgrep))
_TOOLS_GREPUTILS=		egrep fgrep grep
.  if !empty(PKGPATH:Mtextproc/grep)
.    for _t_ in ${_TOOLS_GREPUTILS}
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    endfor
.  else
.    for _t_ in ${_TOOLS_GREPUTILS}
.      if empty(USE_TOOLS:M${_t_})
USE_TOOLS+=	${_t_}
.      endif
.    endfor
.    if !empty(_TOOLS_USE_PKGSRC.egrep:M[yY][eE][sS]) || \
        !empty(_TOOLS_USE_PKGSRC.fgrep:M[yY][eE][sS]) || \
        !empty(_TOOLS_USE_PKGSRC.grep:M[yY][eE][sS])
${TOOLS_DEPENDS.grep}+=		grep>=2.5.1:../../textproc/grep
.      for _t_ in ${_TOOLS_GREPUTILS}
_TOOLS_USE_PKGSRC.${_t_}=	yes
TOOLS_SYMLINK+=			${_t_}
TOOLS_REAL_CMD.${_t_}=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.        if exists(${TOOLS_REAL_CMD.${_t_}})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}}
.        endif
.      endfor
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.file) && !empty(USE_TOOLS:Mfile)
.  if !empty(PKGPATH:Msysutils/file)
MAKEFLAGS+=			TOOLS_IGNORE.file=
.  elif !empty(_TOOLS_USE_PKGSRC.file:M[yY][eE][sS])
${TOOLS_DEPENDS.file}+=		file>=4.13:../../sysutils/file
TOOLS_SYMLINK+=			file
TOOLS_REAL_CMD.file=		${LOCALBASE}/bin/file
.    if exists(${TOOLS_REAL_CMD.file})
${_TOOLS_VARNAME.file}=	${TOOLS_REAL_CMD.file}
.    endif
.  endif
.endif

.if (!defined(TOOLS_IGNORE.find) && \
     !defined(TOOLS_IGNORE.xargs)) && \
    (!empty(USE_TOOLS:Mfind) || \
     !empty(USE_TOOLS:Mxargs))
_TOOLS_FINDUTILS=		find xargs
.  if !empty(PKGPATH:Msysutils/findutils)
.    for _t_ in ${_TOOLS_FINDUTILS}
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    endfor
.  else
.    for _t_ in ${_TOOLS_FINDUTILS}
.      if empty(USE_TOOLS:M${_t_})
USE_TOOLS+=	${_t_}
.      endif
.    endfor
.    if !empty(_TOOLS_USE_PKGSRC.find:M[yY][eE][sS]) || \
        !empty(_TOOLS_USE_PKGSRC.xargs:M[yY][eE][sS])
${TOOLS_DEPENDS.find}+=		findutils>=4.1:../../sysutils/findutils
.      for _t_ in ${_TOOLS_FINDUTILS}
_TOOLS_USE_PKGSRC.${_t_}=	yes
TOOLS_SYMLINK+=			${_t_}
TOOLS_REAL_CMD.${_t_}=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.        if exists(${TOOLS_REAL_CMD.${_t_}})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}}
.        endif
.      endfor
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gawk) && !empty(USE_TOOLS:Mgawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.gawk=
.  elif !empty(_TOOLS_USE_PKGSRC.gawk:M[yY][eE][sS])
${TOOLS_DEPENDS.gawk}+=		gawk>=3.1.1:../../lang/gawk
TOOLS_SYMLINK+=			gawk
TOOLS_REAL_CMD.gawk=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
.    if exists(${TOOLS_REAL_CMD.gawk})
${_TOOLS_VARNAME.gawk}=		${TOOLS_REAL_CMD.gawk}
.    endif
.  endif
TOOLS_CMD.gawk=			${TOOLS_DIR}/bin/awk
.endif

.if !defined(TOOLS_IGNORE.gm4) && !empty(USE_TOOLS:Mgm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.gm4=
.  elif !empty(_TOOLS_USE_PKGSRC.gm4:M[yY][eE][sS])
${TOOLS_DEPENDS.gm4}+=		m4>=1.4:../../devel/m4
TOOLS_SYMLINK+=			gm4
TOOLS_REAL_CMD.gm4=		${LOCALBASE}/bin/gm4
.    if exists(${TOOLS_REAL_CMD.gm4})
${_TOOLS_VARNAME.gm4}=		${TOOLS_REAL_CMD.gm4}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gmake) && !empty(USE_TOOLS:Mgmake)
.  if !empty(PKGPATH:Mdevel/gmake)
MAKEFLAGS+=			TOOLS_IGNORE.gmake=
.  elif !empty(_TOOLS_USE_PKGSRC.gmake:M[yY][eE][sS])
${TOOLS_DEPENDS.gmake}+=	gmake>=3.78:../../devel/gmake
TOOLS_SYMLINK+=			gmake
TOOLS_REAL_CMD.gmake=		${LOCALBASE}/bin/gmake
.    if exists(${TOOLS_REAL_CMD.gmake})
${_TOOLS_VARNAME.gmake}=	${TOOLS_REAL_CMD.gmake}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gsed) && !empty(USE_TOOLS:Mgsed)
.  if !empty(PKGPATH:Mtextproc/sed)
MAKEFLAGS+=			TOOLS_IGNORE.gsed=
.  elif !empty(_TOOLS_USE_PKGSRC.gsed:M[yY][eE][sS])
${TOOLS_DEPENDS.gsed}+=		gsed>=3.0.2:../../textproc/gsed
TOOLS_SYMLINK+=			gsed
TOOLS_REAL_CMD.gsed=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed
.    if exists(${TOOLS_REAL_CMD.gsed})
${_TOOLS_VARNAME.gsed}=		${TOOLS_REAL_CMD.gsed}
.    endif
.  endif
TOOLS_CMD.gsed=			${TOOLS_DIR}/bin/sed
.endif

.if (!defined(TOOLS_IGNORE.gunzip) && \
     !defined(TOOLS_IGNORE.gzcat) && \
     !defined(TOOLS_IGNORE.gzip)) && \
    (!empty(USE_TOOLS:Mgunzip) || \
     !empty(USE_TOOLS:Mgzcat) || \
     !empty(USE_TOOLS:Mgzip))
_TOOLS_GZIPUTILS=		gunzip gzcat gzip
.  if !empty(PKGPATH:Marchiver/gzip-base)
.    for _t_ in ${_TOOLS_GZIPUTILS}
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    endfor
.  else
.    for _t_ in ${_TOOLS_GZIPUTILS}
.      if empty(USE_TOOLS:M${_t_})
USE_TOOLS+=	${_t_}
.      endif
.    endfor
.    if !empty(_TOOLS_USE_PKGSRC.gunzip:M[yY][eE][sS]) || \
        !empty(_TOOLS_USE_PKGSRC.gzcat:M[yY][eE][sS]) || \
        !empty(_TOOLS_USE_PKGSRC.gzip:M[yY][eE][sS])
${TOOLS_DEPENDS.gzip}+=		gzip-base>=1.2.4b:../../archivers/gzip-base
.      for _t_ in ${_TOOLS_GZIPUTILS}
_TOOLS_USE_PKGSRC.${_t_}=	yes
TOOLS_SYMLINK+=			${_t_}
TOOLS_REAL_CMD.${_t_}=		${LOCALBASE}/bin/${_t_}
.        if exists(${TOOLS_REAL_CMD.${_t_}})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}}
.        endif
.      endfor
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.lex) && !empty(USE_TOOLS:Mlex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.lex=
.  elif !empty(_TOOLS_USE_PKGSRC.lex:M[yY][eE][sS])
.    include "../../devel/flex/buildlink3.mk"
TOOLS_SYMLINK+=			lex
TOOLS_REAL_CMD.lex=		${LOCALBASE}/bin/flex
.    if exists(${TOOLS_REAL_CMD.lex})
${_TOOLS_VARNAME.lex}=		${TOOLS_REAL_CMD.lex}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  elif !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
${TOOLS_DEPENDS.patch}+=	patch>=2.2:../../devel/patch
TOOLS_SYMLINK+=			patch
TOOLS_REAL_CMD.patch=		${LOCALBASE}/bin/gpatch
.    if exists(${TOOLS_REAL_CMD.patch})
${_TOOLS_VARNAME.patch}=	${TOOLS_REAL_CMD.patch}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.perl) && !empty(USE_TOOLS:Mperl)
.  if !empty(PKGPATH:Mlang/perl5)
MAKEFLAGS+=			TOOLS_IGNORE.perl=
.  elif !empty(_TOOLS_USE_PKGSRC.perl:M[yY][eE][sS])
.    include "../../lang/perl5/buildlink3.mk"
TOOLS_SYMLINK+=			perl
TOOLS_REAL_CMD.perl=		${LOCALBASE}/bin/perl
.    if exists(${TOOLS_REAL_CMD.perl})
${_TOOLS_VARNAME.perl}=		${TOOLS_REAL_CMD.perl}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.tbl) && !empty(USE_TOOLS:Mtbl)
.  if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=			TOOLS_IGNORE.tbl=
.  elif !empty(_TOOLS_USE_PKGSRC.tbl:M[yY][eE][sS])
${TOOLS_DEPENDS.tbl}+=		groff>=1.19nb4:../../textproc/groff
TOOLS_SYMLINK+=			tbl
TOOLS_REAL_CMD.tbl=		${LOCALBASE}/bin/tbl
.    if exists(${TOOLS_REAL_CMD.tbl})
${_TOOLS_VARNAME.tbl}=		${TOOLS_REAL_CMD.tbl}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.yacc) && !empty(USE_TOOLS:Myacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.yacc=
.  elif !empty(_TOOLS_USE_PKGSRC.yacc:M[yY][eE][sS])
${TOOLS_DEPENDS.yacc}+=		bison>=1.0:../../devel/bison
TOOLS_WRAP+=			yacc
TOOLS_REAL_CMD.yacc=		${LOCALBASE}/bin/bison
TOOLS_ARGS.yacc=		-y
.    if exists(${TOOLS_REAL_CMD.yacc})
${_TOOLS_VARNAME.yacc}=		${TOOLS_REAL_CMD.yacc} ${TOOLS_ARGS.yacc}
.    endif
.  endif
.endif

######################################################################

# Set TOOLS_REAL_CMD.<tool> appropriately in the case where we are
# using the system-supplied tool.  Here, we first check to see if
# PLATFORM_TOOL.<tool> is defined.  If it is, then use that as the path
# to the real command and extract any arguments into TOOLS_ARGS.<tool>.
# We also create either a wrapper or a symlink depending on whether
# there are any arguments or not.  If PLATFORM_TOOL.<tool> is undefined
# or emtpy, then we fall back to checking if TOOL is defined.  Lastly,
# always set the TOOL name for each tool to point to the real command,
# e.g., TBL, YACC, etc., provided that "TOOL" has been associated with
# <tool>.
#
.for _t_ in ${_TOOLS_REPLACE_LIST}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(USE_TOOLS:M${_t_}) && \
      !empty(_TOOLS_USE_PKGSRC.${_t_}:M[nN][oO])
.    if defined(PLATFORM_TOOL.${_t_}) && !empty(PLATFORM_TOOL.${_t_})
TOOLS_REAL_CMD.${_t_}?=		\
	${PLATFORM_TOOL.${_t_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_ARGS.${_t_}?=		\
	${PLATFORM_TOOL.${_t_}:C/^/_asdf_/1:N_asdf_*}
${_TOOLS_VARNAME.${_t_}}=	${PLATFORM_TOOL.${_t_}}
.      if !empty(TOOLS_ARGS.${_t_})
TOOLS_WRAP+=			${_t_}
.      else
TOOLS_SYMLINK+=			${_t_}
.      endif
.    elif defined(${_TOOLS_VARNAME.${_t_}})
TOOLS_REAL_CMD.${_t_}?=		\
	${${_TOOLS_VARNAME.${_t_}}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_ARGS.${_t_}?=		\
	${${_TOOLS_VARNAME.${_t_}}:C/^/_asdf_/1:N_asdf_*}
.      if !empty(TOOLS_ARGS.${_t_})
TOOLS_WRAP+=			${_t_}
.      else
TOOLS_SYMLINK+=			${_t_}
.      endif
.    elif defined(_TOOLS_VARNAME.${_t_})
.      if defined(TOOLS_REAL_CMD.${_t_})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}} ${TOOLS_ARGS.${_t_}}
.      else
${_TOOLS_VARNAME.${_t_}}=	${_TOOLS_VARNAME.${_t_}}_not_defined_
.      endif
.    endif
.  endif
.endfor
.undef _t_
