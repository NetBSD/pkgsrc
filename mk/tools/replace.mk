# $NetBSD: replace.mk,v 1.55 2005/05/02 02:50:34 jlam Exp $
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

######################################################################

# Create _USE_TOOLS, a sanitized version of USE_TOOLS that removes the
# tools that are overridden by superseding ones.

_USE_TOOLS:=	${USE_TOOLS:O:u}
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

.if !defined(TOOLS_IGNORE.[) && !empty(_USE_TOOLS:M\[)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.[=
.  elif !empty(_TOOLS_USE_PKGSRC.[:M[yY][eE][sS])
TOOLS_DEPENDS.[?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			[
TOOLS_REAL_CMD.[=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}[
.  endif
.endif

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

.if !defined(TOOLS_IGNORE.basename) && !empty(_USE_TOOLS:Mbasename)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.basename=
.  elif !empty(_TOOLS_USE_PKGSRC.basename:M[yY][eE][sS])
TOOLS_DEPENDS.basename?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			basename
TOOLS_REAL_CMD.basename=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}basename
.    if exists(${TOOLS_REAL_CMD.basename})
${_TOOLS_VARNAME.basename}=	${TOOLS_REAL_CMD.basename}
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

.if !defined(TOOLS_IGNORE.bzcat) && !empty(_USE_TOOLS:Mbzcat)
.  if !empty(PKGPATH:Marchivers/bzip2)
MAKEFLAGS+=			TOOLS_IGNORE.bzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.bzcat:M[yY][eE][sS])
TOOLS_DEPENDS.bzcat?=		bzip2>=0.9.0b:../../archivers/bzip2
TOOLS_SYMLINK+=			bzcat
TOOLS_REAL_CMD.bzcat=		${LOCALBASE}/bin/bzcat
.    if exists(${TOOLS_REAL_CMD.bzcat})
${_TOOLS_VARNAME.bzcat}=	${TOOLS_REAL_CMD.bzcat}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.cat) && !empty(_USE_TOOLS:Mcat)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cat=
.  elif !empty(_TOOLS_USE_PKGSRC.cat:M[yY][eE][sS])
TOOLS_DEPENDS.cat?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			cat
TOOLS_REAL_CMD.cat=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}cat
.    if exists(${TOOLS_REAL_CMD.cat})
${_TOOLS_VARNAME.cat}=		${TOOLS_REAL_CMD.cat}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.chgrp) && !empty(_USE_TOOLS:Mchgrp)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chgrp=
.  elif !empty(_TOOLS_USE_PKGSRC.chgrp:M[yY][eE][sS])
TOOLS_DEPENDS.chgrp?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			chgrp
TOOLS_REAL_CMD.chgrp=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}chgrp
.    if exists(${TOOLS_REAL_CMD.chgrp})
${_TOOLS_VARNAME.chgrp}=	${TOOLS_REAL_CMD.chgrp}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.chmod) && !empty(_USE_TOOLS:Mchmod)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chmod=
.  elif !empty(_TOOLS_USE_PKGSRC.chmod:M[yY][eE][sS])
TOOLS_DEPENDS.chmod?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			chmod
TOOLS_REAL_CMD.chmod=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}chmod
.    if exists(${TOOLS_REAL_CMD.chmod})
${_TOOLS_VARNAME.chmod}=	${TOOLS_REAL_CMD.chmod}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.chown) && !empty(_USE_TOOLS:Mchown)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chown=
.  elif !empty(_TOOLS_USE_PKGSRC.chown:M[yY][eE][sS])
TOOLS_DEPENDS.chown?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			chown
TOOLS_REAL_CMD.chown=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}chown
.    if exists(${TOOLS_REAL_CMD.chown})
${_TOOLS_VARNAME.chown}=	${TOOLS_REAL_CMD.chown}
.    endif
.  endif
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

.if !defined(TOOLS_IGNORE.cp) && !empty(_USE_TOOLS:Mcp)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cp=
.  elif !empty(_TOOLS_USE_PKGSRC.cp:M[yY][eE][sS])
TOOLS_DEPENDS.cp?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			cp
TOOLS_REAL_CMD.cp=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}cp
.    if exists(${TOOLS_REAL_CMD.cp})
${_TOOLS_VARNAME.cp}=		${TOOLS_REAL_CMD.cp}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.cut) && !empty(_USE_TOOLS:Mcut)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cut=
.  elif !empty(_TOOLS_USE_PKGSRC.cut:M[yY][eE][sS])
TOOLS_DEPENDS.cut?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			cut
TOOLS_REAL_CMD.cut=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}cut
.    if exists(${TOOLS_REAL_CMD.cut})
${_TOOLS_VARNAME.cut}=		${TOOLS_REAL_CMD.cut}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.date) && !empty(_USE_TOOLS:Mdate)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.date=
.  elif !empty(_TOOLS_USE_PKGSRC.date:M[yY][eE][sS])
TOOLS_DEPENDS.date?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			date
TOOLS_REAL_CMD.date=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}date
.    if exists(${TOOLS_REAL_CMD.date})
${_TOOLS_VARNAME.date}=		${TOOLS_REAL_CMD.date}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.dirname) && !empty(_USE_TOOLS:Mdirname)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.dirname=
.  elif !empty(_TOOLS_USE_PKGSRC.dirname:M[yY][eE][sS])
TOOLS_DEPENDS.dirname?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			dirname
TOOLS_REAL_CMD.dirname=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}dirname
.    if exists(${TOOLS_REAL_CMD.dirname})
${_TOOLS_VARNAME.dirname}=	${TOOLS_REAL_CMD.dirname}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.echo) && !empty(_USE_TOOLS:Mecho)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.echo=
.  elif !empty(_TOOLS_USE_PKGSRC.echo:M[yY][eE][sS])
TOOLS_DEPENDS.echo?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			echo
TOOLS_REAL_CMD.echo=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}echo
.    if exists(${TOOLS_REAL_CMD.echo})
${_TOOLS_VARNAME.echo}=		${TOOLS_REAL_CMD.echo}
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

.if !defined(TOOLS_IGNORE.env) && !empty(_USE_TOOLS:Menv)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.env=
.  elif !empty(_TOOLS_USE_PKGSRC.env:M[yY][eE][sS])
TOOLS_DEPENDS.env?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			env
TOOLS_REAL_CMD.env=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}env
.    if exists(${TOOLS_REAL_CMD.env})
${_TOOLS_VARNAME.env}=		${TOOLS_REAL_CMD.env}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.expr) && !empty(_USE_TOOLS:Mexpr)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.expr=
.  elif !empty(_TOOLS_USE_PKGSRC.expr:M[yY][eE][sS])
TOOLS_DEPENDS.expr?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			expr
TOOLS_REAL_CMD.expr=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}expr
.    if exists(${TOOLS_REAL_CMD.expr})
${_TOOLS_VARNAME.expr}=		${TOOLS_REAL_CMD.expr}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.false) && !empty(_USE_TOOLS:Mfalse)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.false=
.  elif !empty(_TOOLS_USE_PKGSRC.false:M[yY][eE][sS])
TOOLS_DEPENDS.false?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			false
TOOLS_REAL_CMD.false=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}false
.    if exists(${TOOLS_REAL_CMD.false})
${_TOOLS_VARNAME.false}=	${TOOLS_REAL_CMD.false}
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

.if !defined(TOOLS_IGNORE.head) && !empty(_USE_TOOLS:Mhead)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.head=
.  elif !empty(_TOOLS_USE_PKGSRC.head:M[yY][eE][sS])
TOOLS_DEPENDS.head?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			head
TOOLS_REAL_CMD.head=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}head
.    if exists(${TOOLS_REAL_CMD.head})
${_TOOLS_VARNAME.head}=		${TOOLS_REAL_CMD.head}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.hostname) && !empty(_USE_TOOLS:Mhostname)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.hostname=
.  elif !empty(_TOOLS_USE_PKGSRC.hostname:M[yY][eE][sS])
TOOLS_DEPENDS.hostname?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			hostname
TOOLS_REAL_CMD.hostname=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}hostname
.    if exists(${TOOLS_REAL_CMD.hostname})
${_TOOLS_VARNAME.hostname}=	${TOOLS_REAL_CMD.hostname}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.id) && !empty(_USE_TOOLS:Mid)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.id=
.  elif !empty(_TOOLS_USE_PKGSRC.id:M[yY][eE][sS])
TOOLS_DEPENDS.id?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			id
TOOLS_REAL_CMD.id=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}id
.    if exists(${TOOLS_REAL_CMD.id})
${_TOOLS_VARNAME.id}=		${TOOLS_REAL_CMD.id}
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

.if !defined(TOOLS_IGNORE.ln) && !empty(_USE_TOOLS:Mln)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.ln=
.  elif !empty(_TOOLS_USE_PKGSRC.ln:M[yY][eE][sS])
TOOLS_DEPENDS.ln?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			ln
TOOLS_REAL_CMD.ln=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}ln
.    if exists(${TOOLS_REAL_CMD.ln})
${_TOOLS_VARNAME.ln}=		${TOOLS_REAL_CMD.ln}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.ls) && !empty(_USE_TOOLS:Mls)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.ls=
.  elif !empty(_TOOLS_USE_PKGSRC.ls:M[yY][eE][sS])
TOOLS_DEPENDS.ls?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			ls
TOOLS_REAL_CMD.ls=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}ls
.    if exists(${TOOLS_REAL_CMD.ls})
${_TOOLS_VARNAME.ls}=		${TOOLS_REAL_CMD.ls}
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

.if !defined(TOOLS_IGNORE.mkdir) && !empty(_USE_TOOLS:Mmkdir)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.mkdir=
.  elif !empty(_TOOLS_USE_PKGSRC.mkdir:M[yY][eE][sS])
TOOLS_DEPENDS.mkdir?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_WRAP+=			mkdir
TOOLS_REAL_CMD.mkdir=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}mkdir
TOOLS_ARGS.mkdir=		-p
.    if exists(${TOOLS_REAL_CMD.mkdir})
${_TOOLS_VARNAME.mkdir}=	${TOOLS_REAL_CMD.mkdir} ${TOOLS_ARGS.mkdir}
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

.if !defined(TOOLS_IGNORE.mv) && !empty(_USE_TOOLS:Mmv)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.mv=
.  elif !empty(_TOOLS_USE_PKGSRC.mv:M[yY][eE][sS])
TOOLS_DEPENDS.mv?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			mv
TOOLS_REAL_CMD.mv=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}mv
.    if exists(${TOOLS_REAL_CMD.mv})
${_TOOLS_VARNAME.mv}=		${TOOLS_REAL_CMD.mv}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.nice) && !empty(_USE_TOOLS:Mnice)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.nice=
.  elif !empty(_TOOLS_USE_PKGSRC.nice:M[yY][eE][sS])
TOOLS_DEPENDS.nice?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			nice
TOOLS_REAL_CMD.nice=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}nice
.    if exists(${TOOLS_REAL_CMD.nice})
${_TOOLS_VARNAME.nice}=		${TOOLS_REAL_CMD.nice}
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

.if !defined(TOOLS_IGNORE.pwd) && !empty(_USE_TOOLS:Mpwd)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.pwd=
.  elif !empty(_TOOLS_USE_PKGSRC.pwd:M[yY][eE][sS])
TOOLS_DEPENDS.pwd?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			pwd
TOOLS_REAL_CMD.pwd=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}pwd
.    if exists(${TOOLS_REAL_CMD.pwd})
${_TOOLS_VARNAME.pwd}=		${TOOLS_REAL_CMD.pwd}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.rm) && !empty(_USE_TOOLS:Mrm)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.rm=
.  elif !empty(_TOOLS_USE_PKGSRC.rm:M[yY][eE][sS])
TOOLS_DEPENDS.rm?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			rm
TOOLS_REAL_CMD.rm=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}rm
.    if exists(${TOOLS_REAL_CMD.rm})
${_TOOLS_VARNAME.rm}=		${TOOLS_REAL_CMD.rm}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.rmdir) && !empty(_USE_TOOLS:Mrmdir)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.rmdir=
.  elif !empty(_TOOLS_USE_PKGSRC.rmdir:M[yY][eE][sS])
TOOLS_DEPENDS.rmdir?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			rmdir
TOOLS_REAL_CMD.rmdir=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}rmdir
.    if exists(${TOOLS_REAL_CMD.rmdir})
${_TOOLS_VARNAME.rmdir}=	${TOOLS_REAL_CMD.rmdir}
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

.if !defined(TOOLS_IGNORE.sort) && !empty(_USE_TOOLS:Msort)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.sort=
.  elif !empty(_TOOLS_USE_PKGSRC.sort:M[yY][eE][sS])
TOOLS_DEPENDS.sort?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			sort
TOOLS_REAL_CMD.sort=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sort
.    if exists(${TOOLS_REAL_CMD.sort})
${_TOOLS_VARNAME.sort}=		${TOOLS_REAL_CMD.sort}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.tail) && !empty(_USE_TOOLS:Mtail)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tail=
.  elif !empty(_TOOLS_USE_PKGSRC.tail:M[yY][eE][sS])
TOOLS_DEPENDS.tail?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			tail
TOOLS_REAL_CMD.tail=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tail
.    if exists(${TOOLS_REAL_CMD.tail})
${_TOOLS_VARNAME.tail}=		${TOOLS_REAL_CMD.tail}
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

.if !defined(TOOLS_IGNORE.tee) && !empty(_USE_TOOLS:Mtee)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tee=
.  elif !empty(_TOOLS_USE_PKGSRC.tee:M[yY][eE][sS])
TOOLS_DEPENDS.tee?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			tee
TOOLS_REAL_CMD.tee=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tee
.    if exists(${TOOLS_REAL_CMD.tee})
${_TOOLS_VARNAME.tee}=		${TOOLS_REAL_CMD.tee}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.test) && !empty(_USE_TOOLS:Mtest)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.test=
.  elif !empty(_TOOLS_USE_PKGSRC.test:M[yY][eE][sS])
TOOLS_DEPENDS.test?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			test
TOOLS_REAL_CMD.test=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}test
.    if exists(${TOOLS_REAL_CMD.test})
${_TOOLS_VARNAME.test}=		${TOOLS_REAL_CMD.test}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.touch) && !empty(_USE_TOOLS:Mtouch)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.touch=
.  elif !empty(_TOOLS_USE_PKGSRC.touch:M[yY][eE][sS])
TOOLS_DEPENDS.touch?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			touch
TOOLS_REAL_CMD.touch=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}touch
.    if exists(${TOOLS_REAL_CMD.touch})
${_TOOLS_VARNAME.touch}=	${TOOLS_REAL_CMD.touch}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.tr) && !empty(_USE_TOOLS:Mtr)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tr=
.  elif !empty(_TOOLS_USE_PKGSRC.tr:M[yY][eE][sS])
TOOLS_DEPENDS.tr?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			tr
TOOLS_REAL_CMD.tr=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tr
.    if exists(${TOOLS_REAL_CMD.tr})
${_TOOLS_VARNAME.tr}=		${TOOLS_REAL_CMD.tr}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.true) && !empty(_USE_TOOLS:Mtrue)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.true=
.  elif !empty(_TOOLS_USE_PKGSRC.true:M[yY][eE][sS])
TOOLS_DEPENDS.true?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			true
TOOLS_REAL_CMD.true=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}true
.    if exists(${TOOLS_REAL_CMD.true})
${_TOOLS_VARNAME.true}=		${TOOLS_REAL_CMD.true}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.tsort) && !empty(_USE_TOOLS:Mtsort)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tsort=
.  elif !empty(_TOOLS_USE_PKGSRC.tsort:M[yY][eE][sS])
TOOLS_DEPENDS.tsort?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			tsort
TOOLS_REAL_CMD.tsort=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tsort
.    if exists(${TOOLS_REAL_CMD.tsort})
${_TOOLS_VARNAME.tsort}=	${TOOLS_REAL_CMD.tsort}
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.wc) && !empty(_USE_TOOLS:Mwc)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.wc=
.  elif !empty(_TOOLS_USE_PKGSRC.wc:M[yY][eE][sS])
TOOLS_DEPENDS.wc?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_SYMLINK+=			wc
TOOLS_REAL_CMD.wc=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}wc
.    if exists(${TOOLS_REAL_CMD.wc})
${_TOOLS_VARNAME.wc}=		${TOOLS_REAL_CMD.wc}
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
# TOOLS_PLATFORM.<tool> is defined.  If it is, then use that as the
# path to the real command and extract any arguments into
# TOOLS_ARGS.<tool>.  We also create either a wrapper or a symlink
# depending on whether # there are any arguments or not.  Lastly,
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
.      if defined(_TOOLS_VARNAME.${_t_})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_PLATFORM.${_t_}}
.      endif
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
