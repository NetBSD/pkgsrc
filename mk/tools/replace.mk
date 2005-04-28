# $NetBSD: replace.mk,v 1.49 2005/04/28 15:51:10 jlam Exp $
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
# but this may be changed by explicitly setting TOOLS_DEPMETHOD.<tool>,
# e.g.:
#
#	TOOLS_DEPMETHOD.tbl=	DEPENDS
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

# These are the platform-specific lists of system-supplied tools.
#
# XXX These should eventually just migrate over to the appropriate
# XXX pkgsrc/mk/platform/${OPSYS}.mk file.
#
.include "../../mk/tools/bootstrap.mk"
.if exists(../../mk/tools/tools.${OPSYS}.mk)
.  include "../../mk/tools/tools.${OPSYS}.mk"
.endif

# This is an exhaustive list of tools for which we have pkgsrc
# replacements.
#
_TOOLS_REPLACE_LIST=	awk bison cmp egrep fgrep file find gawk gm4	\
			gmake grep gsed gtar gunzip gzcat gzip lex m4	\
			mtree patch pax sed sh shlock tbl xargs	yacc

# "TOOL" variable names associated with each of the tools
_TOOLS_VARNAME.awk=	AWK
_TOOLS_VARNAME.bison=	YACC
_TOOLS_VARNAME.cmp=	CMP
_TOOLS_VARNAME.egrep=	EGREP
_TOOLS_VARNAME.fgrep=	FGREP
_TOOLS_VARNAME.file=	FILE_CMD
_TOOLS_VARNAME.find=	FIND
_TOOLS_VARNAME.gawk=	AWK
_TOOLS_VARNAME.gm4=	M4
_TOOLS_VARNAME.gmake=	GMAKE
_TOOLS_VARNAME.grep=	GREP
_TOOLS_VARNAME.gsed=	SED
_TOOLS_VARNAME.gtar=	GTAR
_TOOLS_VARNAME.gunzip=	GUNZIP_CMD
_TOOLS_VARNAME.gzcat=	GZCAT
_TOOLS_VARNAME.gzip=	GZIP_CMD
_TOOLS_VARNAME.lex=	LEX
_TOOLS_VARNAME.m4=	M4
_TOOLS_VARNAME.mtree=	MTREE
_TOOLS_VARNAME.patch=	PATCH
_TOOLS_VARNAME.pax=	PAX
_TOOLS_VARNAME.sed=	SED
_TOOLS_VARNAME.sh=	SH
_TOOLS_VARNAME.shlock=	SHLOCK
_TOOLS_VARNAME.tbl=	TBL
_TOOLS_VARNAME.xargs=	XARGS
_TOOLS_VARNAME.yacc=	YACC

######################################################################

# Create _USE_TOOLS, a sanitized version of USE_TOOLS that removes the
# tools that are overridden by superseding ones.

_USE_TOOLS:=	${USE_TOOLS}
.if !empty(USE_TOOLS:Mbison)		# bison > yacc
_USE_TOOLS:=	${_USE_TOOLS:Nyacc}
.endif
.if !empty(USE_TOOLS:Mgawk)		# gawk > awk
_USE_TOOLS:=	${_USE_TOOLS:Nawk}
.endif
.if !empty(USE_TOOLS:Mgm4)		# gm4 > m4
_USE_TOOLS:=	${_USE_TOOLS:Nm4}
.endif
.if !empty(USE_TOOLS:Mgsed)		# gsed > sed
_USE_TOOLS:=	${_USE_TOOLS:Nsed}
.endif

######################################################################

# _TOOLS_USE_PKGSRC.<tool> is "yes" or "no" depending on whether we're
# using a pkgsrc-supplied tool to replace the system-supplied one.  We
# use the system-supplied one if TOOLS_PLATFORM.<tool> is non-empty, or
# otherwise if this is a particular ${MACHINE_PLATFORM} listed above.
#
.for _t_ in ${_USE_TOOLS}
.  if defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
_TOOLS_USE_PKGSRC.${_t_}?=	no
.  endif
_TOOLS_USE_PKGSRC.${_t_}?=	yes
.endfor
.undef _t_

# TOOLS_DEPMETHOD.<tool> defaults to BUILD_DEPENDS.
.for _t_ in ${_USE_TOOLS}
TOOLS_DEPMETHOD.${_t_}?=	BUILD_DEPENDS
.endfor
.undef _t_

######################################################################

# For each of the blocks below, we create either symlinks or wrappers
# for each of the tools requested.  We need to be careful that we don't
# get into dependency loops; do this by setting and checking the value
# of TOOLS_IGNORE.<tool>.  If we're using the system-supplied tool, we
# defer the setting of TOOLS_REAL_CMD.<tool> until the loop at the end.

.if !defined(TOOLS_IGNORE.awk) && !empty(_USE_TOOLS:Mawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.awk=
.  elif !empty(_TOOLS_USE_PKGSRC.awk:M[yY][eE][sS])
TOOLS_DEPENDS.awk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_SYMLINK+=			awk
TOOLS_REAL_CMD.awk=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
.    if exists(${TOOLS_REAL_CMD.awk})
${_TOOLS_VARNAME.awk}=		${TOOLS_REAL_CMD.awk}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.bison) && !empty(_USE_TOOLS:Mbison)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison=
.  elif !empty(_TOOLS_USE_PKGSRC.bison:M[yY][eE][sS])
TOOLS_DEPENDS.bison?=		bison>=1.0:../../devel/bison
TOOLS_WRAP+=			bison
TOOLS_REAL_CMD.bison=		${LOCALBASE}/bin/bison
TOOLS_ARGS.bison=		-y
.    if exists(${TOOLS_REAL_CMD.bison})
${_TOOLS_VARNAME.bison}=	${TOOLS_REAL_CMD.bison} ${TOOLS_ARGS.bison}
.    endif
.  endif
TOOLS_CMD.bison=		${TOOLS_DIR}/bin/yacc
.endif

.if !defined(TOOLS_IGNORE.cmp) && !empty(_USE_TOOLS:Mcmp)
.  if !empty(PKGPATH:Mdevel/diffutils)
MAKEFLAGS+=			TOOLS_IGNORE.cmp=
.  elif !empty(_TOOLS_USE_PKGSRC.cmp:M[yY][eE][sS])
TOOLS_DEPENDS.cmp?=		diffutils>=2.8.1:../../devel/diffutils
TOOLS_SYMLINK+=			cmp
TOOLS_REAL_CMD.cmp=		${LOCALBASE}/bin/cmp
.    if exists(${TOOLS_REAL_CMD.cmp})
${_TOOLS_VARNAME.cmp}=		${TOOLS_REAL_CMD.cmp}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.egrep) && !empty(_USE_TOOLS:Megrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.egrep=
.  elif !empty(_TOOLS_USE_PKGSRC.egrep:M[yY][eE][sS])
TOOLS_DEPENDS.egrep?=		grep>=2.5.1:../../textproc/grep
TOOLS_SYMLINK+=			egrep
TOOLS_REAL_CMD.egrep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}egrep
.    if exists(${TOOLS_REAL_CMD.egrep})
${_TOOLS_VARNAME.egrep}=	${TOOLS_REAL_CMD.egrep}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.fgrep) && !empty(_USE_TOOLS:Mfgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.fgrep=
.  elif !empty(_TOOLS_USE_PKGSRC.fgrep:M[yY][eE][sS])
TOOLS_DEPENDS.fgrep?=		grep>=2.5.1:../../textproc/grep
TOOLS_SYMLINK+=			fgrep
TOOLS_REAL_CMD.fgrep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}fgrep
.    if exists(${TOOLS_REAL_CMD.fgrep})
${_TOOLS_VARNAME.fgrep}=	${TOOLS_REAL_CMD.fgrep}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.file) && !empty(_USE_TOOLS:Mfile)
.  if !empty(PKGPATH:Msysutils/file)
MAKEFLAGS+=			TOOLS_IGNORE.file=
.  elif !empty(_TOOLS_USE_PKGSRC.file:M[yY][eE][sS])
TOOLS_DEPENDS.file?=		file>=4.13:../../sysutils/file
TOOLS_SYMLINK+=			file
TOOLS_REAL_CMD.file=		${LOCALBASE}/bin/file
.    if exists(${TOOLS_REAL_CMD.file})
${_TOOLS_VARNAME.file}=	${TOOLS_REAL_CMD.file}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.find) && !empty(_USE_TOOLS:Mfind)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.find=
.  elif !empty(_TOOLS_USE_PKGSRC.find:M[yY][eE][sS])
TOOLS_DEPENDS.find?=		findutils>=4.1:../../sysutils/findutils
TOOLS_SYMLINK+=			find
TOOLS_REAL_CMD.find=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}find
.    if exists(${TOOLS_REAL_CMD.find})
${_TOOLS_VARNAME.find}=		${TOOLS_REAL_CMD.find}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gawk) && !empty(_USE_TOOLS:Mgawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.gawk=
.  elif !empty(_TOOLS_USE_PKGSRC.gawk:M[yY][eE][sS])
TOOLS_DEPENDS.gawk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_SYMLINK+=			gawk
TOOLS_REAL_CMD.gawk=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
.    if exists(${TOOLS_REAL_CMD.gawk})
${_TOOLS_VARNAME.gawk}=		${TOOLS_REAL_CMD.gawk}
.    endif
.  endif
TOOLS_CMD.gawk=			${TOOLS_DIR}/bin/awk
.endif

.if !defined(TOOLS_IGNORE.gm4) && !empty(_USE_TOOLS:Mgm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.gm4=
.  elif !empty(_TOOLS_USE_PKGSRC.gm4:M[yY][eE][sS])
TOOLS_DEPENDS.gm4?=		m4>=1.4:../../devel/m4
TOOLS_SYMLINK+=			gm4
TOOLS_REAL_CMD.gm4=		${LOCALBASE}/bin/gm4
.    if exists(${TOOLS_REAL_CMD.gm4})
${_TOOLS_VARNAME.gm4}=		${TOOLS_REAL_CMD.gm4}
.    endif
.  endif
TOOLS_CMD.gm4=			${TOOLS_DIR}/bin/m4
.endif

.if !defined(TOOLS_IGNORE.gmake) && !empty(_USE_TOOLS:Mgmake)
.  if !empty(PKGPATH:Mdevel/gmake)
MAKEFLAGS+=			TOOLS_IGNORE.gmake=
.  elif !empty(_TOOLS_USE_PKGSRC.gmake:M[yY][eE][sS])
TOOLS_DEPENDS.gmake?=		gmake>=3.78:../../devel/gmake
TOOLS_SYMLINK+=			gmake
TOOLS_REAL_CMD.gmake=		${LOCALBASE}/bin/gmake
.    if exists(${TOOLS_REAL_CMD.gmake})
${_TOOLS_VARNAME.gmake}=	${TOOLS_REAL_CMD.gmake}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.grep) && !empty(_USE_TOOLS:Mgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.grep=
.  elif !empty(_TOOLS_USE_PKGSRC.grep:M[yY][eE][sS])
TOOLS_DEPENDS.grep?=		grep>=2.5.1:../../textproc/grep
TOOLS_SYMLINK+=			grep
TOOLS_REAL_CMD.grep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep
.    if exists(${TOOLS_REAL_CMD.grep})
${_TOOLS_VARNAME.grep}=		${TOOLS_REAL_CMD.grep}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gsed) && !empty(_USE_TOOLS:Mgsed)
.  if !empty(PKGPATH:Mtextproc/gsed)
MAKEFLAGS+=			TOOLS_IGNORE.gsed=
.  elif !empty(_TOOLS_USE_PKGSRC.gsed:M[yY][eE][sS])
TOOLS_DEPENDS.gsed?=		gsed>=3.0.2:../../textproc/gsed
TOOLS_SYMLINK+=			gsed
TOOLS_REAL_CMD.gsed=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed
.    if exists(${TOOLS_REAL_CMD.gsed})
${_TOOLS_VARNAME.gsed}=		${TOOLS_REAL_CMD.gsed}
.    endif
.  endif
TOOLS_CMD.gsed=			${TOOLS_DIR}/bin/sed
.endif

.if !defined(TOOLS_IGNORE.gtar) && !empty(_USE_TOOLS:Mgtar)
.  if !empty(PKGPATH:Marchivers/pax)
MAKEFLAGS+=			TOOLS_IGNORE.gtar=
.  elif !empty(_TOOLS_USE_PKGSRC.gtar:M[yY][eE][sS])
#
# This is installed by pkgsrc bootstrap, and is never registered, so
# comment out the dependency on it.
#
#TOOLS_DEPENDS.gtar?=		pax>=20040802:../../archivers/pax
TOOLS_SYMLINK+=			gtar
TOOLS_REAL_CMD.gtar=		${LOCALBASE}/bin/tar
.    if exists(${TOOLS_REAL_CMD.gtar})
${_TOOLS_VARNAME.gtar}=		${TOOLS_REAL_CMD.gtar}
.    endif
.  endif
TOOLS_CMD.gtar=			${TOOLS_DIR}/bin/tar
.endif

.if !defined(TOOLS_IGNORE.gunzip) && !empty(_USE_TOOLS:Mgunzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gunzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gunzip:M[yY][eE][sS])
TOOLS_DEPENDS.gunzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_SYMLINK+=			gunzip
TOOLS_REAL_CMD.gunzip=		${LOCALBASE}/bin/gunzip
.    if exists(${TOOLS_REAL_CMD.gunzip})
${_TOOLS_VARNAME.gunzip}=	${TOOLS_REAL_CMD.gunzip}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzcat) && !empty(_USE_TOOLS:Mgzcat)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.gzcat:M[yY][eE][sS])
TOOLS_DEPENDS.gzcat?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_SYMLINK+=			gzcat
TOOLS_REAL_CMD.gzcat=		${LOCALBASE}/bin/gzcat
.    if exists(${TOOLS_REAL_CMD.gzcat})
${_TOOLS_VARNAME.gzcat}=	${TOOLS_REAL_CMD.gzcat}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzip) && !empty(_USE_TOOLS:Mgzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gzip:M[yY][eE][sS])
TOOLS_DEPENDS.gzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_SYMLINK+=			gzip
TOOLS_REAL_CMD.gzip=		${LOCALBASE}/bin/gzip
.    if exists(${TOOLS_REAL_CMD.gzip})
${_TOOLS_VARNAME.gzip}=		${TOOLS_REAL_CMD.gzip}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.lex) && !empty(_USE_TOOLS:Mlex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.lex=
.  elif !empty(_TOOLS_USE_PKGSRC.lex:M[yY][eE][sS])
.    include "../../devel/flex/buildlink3.mk"
TOOLS_DEPENDS.lex?=	${BUILDLINK_DEPENDS.flex}:${BUILDLINK_PKGSRCDIR.flex}
TOOLS_SYMLINK+=			lex
TOOLS_REAL_CMD.lex=		${LOCALBASE}/bin/flex
.    if exists(${TOOLS_REAL_CMD.lex})
${_TOOLS_VARNAME.lex}=		${TOOLS_REAL_CMD.lex}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.m4) && !empty(_USE_TOOLS:Mm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.m4=
.  elif !empty(_TOOLS_USE_PKGSRC.m4:M[yY][eE][sS])
TOOLS_DEPENDS.m4?=		m4>=1.4:../../devel/m4
TOOLS_SYMLINK+=			m4
TOOLS_REAL_CMD.m4=		${LOCALBASE}/bin/gm4
.    if exists(${TOOLS_REAL_CMD.m4})
${_TOOLS_VARNAME.m4}=		${TOOLS_REAL_CMD.m4}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.mtree) && !empty(_USE_TOOLS:Mmtree)
.  if !empty(PKGPATH:Mpkgtools/mtree)
MAKEFLAGS+=			TOOLS_IGNORE.mtree=
.  elif !empty(_TOOLS_USE_PKGSRC.mtree:M[yY][eE][sS])
#
# This is installed by pkgsrc bootstrap, and is never registered, so
# comment out the dependency on it.
#
#TOOLS_DEPENDS.mtree?=		mtree>=20040722:../../pkgtools/mtree
TOOLS_SYMLINK+=			mtree
TOOLS_REAL_CMD.mtree=		${LOCALBASE}/bin/mtree
.    if exists(${TOOLS_REAL_CMD.mtree})
${_TOOLS_VARNAME.mtree}=	${TOOLS_REAL_CMD.mtree}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(_USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  elif !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
TOOLS_DEPENDS.patch?=		patch>=2.2:../../devel/patch
TOOLS_SYMLINK+=			patch
TOOLS_REAL_CMD.patch=		${LOCALBASE}/bin/gpatch
.    if exists(${TOOLS_REAL_CMD.patch})
${_TOOLS_VARNAME.patch}=	${TOOLS_REAL_CMD.patch}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.pax) && !empty(_USE_TOOLS:Mpax)
.  if !empty(PKGPATH:Marchivers/pax)
MAKEFLAGS+=			TOOLS_IGNORE.pax=
.  elif !empty(_TOOLS_USE_PKGSRC.pax:M[yY][eE][sS])
#
# This is installed by pkgsrc bootstrap, and is never registered, so
# comment out the dependency on it.
#
#TOOLS_DEPENDS.pax?=		pax>=20040802:../../archivers/pax
TOOLS_SYMLINK+=			pax
TOOLS_REAL_CMD.pax=		${LOCALBASE}/bin/pax
.    if exists(${TOOLS_REAL_CMD.pax})
${_TOOLS_VARNAME.pax}=		${TOOLS_REAL_CMD.pax}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.sed) && !empty(_USE_TOOLS:Msed)
.  if !empty(PKGPATH:Mtextproc/nbsed)
MAKEFLAGS+=			TOOLS_IGNORE.sed=
.  elif !empty(_TOOLS_USE_PKGSRC.sed:M[yY][eE][sS])
TOOLS_DEPENDS.sed?=		nbsed>=20040821:../../textproc/nbsed
TOOLS_SYMLINK+=			sed
TOOLS_REAL_CMD.sed=		${LOCALBASE}/bin/nbsed
.    if exists(${TOOLS_REAL_CMD.sed})
${_TOOLS_VARNAME.sed}=	${TOOLS_REAL_CMD.sed}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.sh) && !empty(_USE_TOOLS:Msh)
.  if !empty(PKGPATH:Mshells/pdksh)
MAKEFLAGS+=			TOOLS_IGNORE.sh=
.  elif !empty(_TOOLS_USE_PKGSRC.sh:M[yY][eE][sS])
TOOLS_DEPENDS.sh?=		pdksh>=5.2.14:../../shells/pdksh
TOOLS_SYMLINK+=			sh
TOOLS_REAL_CMD.sh=		${LOCALBASE}/bin/pdksh
.    if exists(${TOOLS_REAL_CMD.sh})
${_TOOLS_VARNAME.sh}=		${TOOLS_REAL_CMD.sh}
.    endif
.  endif
TOOLS_CMD.sh=			${TOOLS_DIR}/bin/sh
.endif

.if !defined(TOOLS_IGNORE.shlock) && !empty(_USE_TOOLS:Mshlock)
.  if !empty(PKGPATH:Mpkgtools/shlock)
MAKEFLAGS+=			TOOLS_IGNORE.shlock=
.  elif !empty(_TOOLS_USE_PKGSRC.shlock:M[yY][eE][sS])
TOOLS_DEPENDS.shlock?=		shlock>=20020114:../../pkgtools/shlock
TOOLS_SYMLINK+=			shlock
TOOLS_REAL_CMD.shlock=		${LOCALBASE}/bin/shlock
.    if exists(${TOOLS_REAL_CMD.shlock})
${_TOOLS_VARNAME.shlock}=	${TOOLS_REAL_CMD.shlock}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.tbl) && !empty(_USE_TOOLS:Mtbl)
.  if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=			TOOLS_IGNORE.tbl=
.  elif !empty(_TOOLS_USE_PKGSRC.tbl:M[yY][eE][sS])
TOOLS_DEPENDS.tbl?=		groff>=1.19nb4:../../textproc/groff
TOOLS_SYMLINK+=			tbl
TOOLS_REAL_CMD.tbl=		${LOCALBASE}/bin/tbl
.    if exists(${TOOLS_REAL_CMD.tbl})
${_TOOLS_VARNAME.tbl}=		${TOOLS_REAL_CMD.tbl}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.xargs) && !empty(_USE_TOOLS:Mxargs)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.xargs=
.  elif !empty(_TOOLS_USE_PKGSRC.xargs:M[yY][eE][sS])
TOOLS_DEPENDS.xargs?=		findutils>=4.1:../../sysutils/findutils
TOOLS_SYMLINK+=			xargs
TOOLS_REAL_CMD.xargs=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}xargs
.    if exists(${TOOLS_REAL_CMD.xargs})
${_TOOLS_VARNAME.xargs}=	${TOOLS_REAL_CMD.xargs}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.yacc) && !empty(_USE_TOOLS:Myacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.yacc=
.  elif !empty(_TOOLS_USE_PKGSRC.yacc:M[yY][eE][sS])
TOOLS_DEPENDS.yacc?=		bison>=1.0:../../devel/bison
TOOLS_WRAP+=			yacc
TOOLS_REAL_CMD.yacc=		${LOCALBASE}/bin/bison
TOOLS_ARGS.yacc=		-y
.    if exists(${TOOLS_REAL_CMD.yacc})
${_TOOLS_VARNAME.yacc}=		${TOOLS_REAL_CMD.yacc} ${TOOLS_ARGS.yacc}
.    endif
.  endif
.endif

# Add the dependencies for each pkgsrc-supplied tool.
.for _t_ in ${_USE_TOOLS}
.  if defined(TOOLS_DEPMETHOD.${_t_}) && defined(TOOLS_DEPENDS.${_t_})
.    if empty(${TOOLS_DEPMETHOD.${_t_}}:M${TOOLS_DEPENDS.${_t_}})
${TOOLS_DEPMETHOD.${_t_}}+=	${TOOLS_DEPENDS.${_t_}}
.    endif
.  endif
.endfor

######################################################################

# Set TOOLS_REAL_CMD.<tool> appropriately in the case where we are
# using the system-supplied tool.  Here, we first check to see if
# TOOLS_PLATFORM.<tool> is defined.  If it is, then use that as the path
# to the real command and extract any arguments into TOOLS_ARGS.<tool>.
# We also create either a wrapper or a symlink depending on whether
# there are any arguments or not.  If TOOLS_PLATFORM.<tool> is undefined
# or empty, then we fall back to checking if TOOL is defined.  Lastly,
# always set the TOOL name for each tool to point to the real command,
# e.g., TBL, YACC, etc., provided that "TOOL" has been associated with
# <tool>.
#
.for _t_ in ${_USE_TOOLS}
.  if !defined(TOOLS_IGNORE.${_t_}) && \
      !empty(_TOOLS_USE_PKGSRC.${_t_}:M[nN][oO])
.    if defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
TOOLS_REAL_CMD.${_t_}?=		\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_ARGS.${_t_}?=		\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:N_asdf_*}
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_PLATFORM.${_t_}}
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
