# $NetBSD: replace.mk,v 1.75 2005/05/15 03:27:20 jlam Exp $
#
# This Makefile fragment handles "replacements" of system-supplied
# tools with pkgsrc versions.
#
# The replacement tools are placed under ${TOOLS_DIR} so that they
# appear earlier in the search path when invoked using the bare name
# of the tool.
#
# "TOOLS_TOOL" variables, e.g. TOOLS_AWK, TOOLS_SED, etc. are set to
# the full command lines necessary to invoke the real tools on the
# filesystem, and represent the tools required by the package.
#
# "TOOL" variables, e.g. AWK, SED, etc. are set to the full command
# lines necessary to invoke the real tools on the filesystem, and
# represent the tools required by pkgsrc itself.
#
# The tools that could be replaced with pkgsrc counterparts (usually
# GNU versions of the tools) that are required by pkgsrc itself, i.e.
# in targets that are part of pkgsrc infrastructure or part of the
# package Makefile, should be listed as:
#
#	PKGSRC_USE_TOOLS+=	awk sed
#
# The tools that are required by the package itself, i.e. within the
# software's own build system, should be listed as:
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

.include "../../mk/tools/imake.mk"

######################################################################

# Create _USE_TOOLS, a sanitized version of PKGSRC_USE_TOOLS and
# USE_TOOLS that removes the ones that are overridden by superseding
# ones.
#
.if !defined(_USE_TOOLS)
_USE_TOOLS:=	${PKGSRC_USE_TOOLS} ${USE_TOOLS}
_USE_TOOLS:=	${_USE_TOOLS:O:u}
.  if !empty(USE_TOOLS:Mbison)		# bison > yacc
_USE_TOOLS:=	${_USE_TOOLS:Nyacc}
.  endif
.  if !empty(USE_TOOLS:Mgawk)		# gawk > awk
_USE_TOOLS:=	${_USE_TOOLS:Nawk}
.  endif
.  if !empty(USE_TOOLS:Mgm4)		# gm4 > m4
_USE_TOOLS:=	${_USE_TOOLS:Nm4}
.  endif
.  if !empty(USE_TOOLS:Mgsed)		# gsed > sed
_USE_TOOLS:=	${_USE_TOOLS:Nsed}
.  endif
.endif
MAKEVARS+=	_USE_TOOLS

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
# of TOOLS_IGNORE.<tool>.  These blocks handle the case where we are
# using the pkgsrc-supplied tool.
#
# Always set the "TOOLS_TOOL" name for each tool to point to the real
# command, e.g., TOOLS_TBL, TOOLS_YACC, etc., provided that "TOOL" has
# been associated with <tool>.
#
.if !defined(TOOLS_IGNORE.[) && !empty(_USE_TOOLS:M\[)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.[=
.  elif !empty(_TOOLS_USE_PKGSRC.[:M[yY][eE][sS])
TOOLS_DEPENDS.[?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			[
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.[=coreutils
TOOLS_REAL_CMD.[=		${TOOLS_PREFIX.[}/bin/${GNU_PROGRAM_PREFIX}[
.  endif
.endif

.if !defined(TOOLS_IGNORE.awk) && !empty(_USE_TOOLS:Mawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.awk=
.  elif !empty(_TOOLS_USE_PKGSRC.awk:M[yY][eE][sS])
TOOLS_DEPENDS.awk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_CREATE+=			awk
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.awk=gawk
TOOLS_REAL_CMD.awk=		${TOOLS_PREFIX.awk}/bin/${GNU_PROGRAM_PREFIX}awk
TOOLS_${_TOOLS_VARNAME.awk}=	${TOOLS_REAL_CMD.awk}
.  endif
.endif

.if !defined(TOOLS_IGNORE.basename) && !empty(_USE_TOOLS:Mbasename)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.basename=
.  elif !empty(_TOOLS_USE_PKGSRC.basename:M[yY][eE][sS])
TOOLS_DEPENDS.basename?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			basename
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.basename=coreutils
TOOLS_REAL_CMD.basename=	${TOOLS_PREFIX.basename}/bin/${GNU_PROGRAM_PREFIX}basename
TOOLS_${_TOOLS_VARNAME.basename}=	${TOOLS_REAL_CMD.basename}
.  endif
.endif

.if !defined(TOOLS_IGNORE.bison) && !empty(_USE_TOOLS:Mbison)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison=
.  elif !empty(_TOOLS_USE_PKGSRC.bison:M[yY][eE][sS])
TOOLS_DEPENDS.bison?=		bison>=1.0:../../devel/bison
TOOLS_CREATE+=			bison
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bison=bison
TOOLS_REAL_CMD.bison=		${TOOLS_PREFIX.bison}/bin/bison
TOOLS_REAL_ARGS.bison=		-y
TOOLS_${_TOOLS_VARNAME.bison}=	${TOOLS_REAL_CMD.bison} ${TOOLS_REAL_ARGS.bison}
.  endif
TOOLS_CMD.bison=		${TOOLS_DIR}/bin/yacc
.endif

.if !defined(TOOLS_IGNORE.bzcat) && !empty(_USE_TOOLS:Mbzcat)
.  if !empty(PKGPATH:Marchivers/bzip2)
MAKEFLAGS+=			TOOLS_IGNORE.bzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.bzcat:M[yY][eE][sS])
TOOLS_DEPENDS.bzcat?=		bzip2>=0.9.0b:../../archivers/bzip2
TOOLS_CREATE+=			bzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bzcat=bzip2
TOOLS_REAL_CMD.bzcat=		${TOOLS_PREFIX.bzcat}/bin/bzcat
TOOLS_${_TOOLS_VARNAME.bzcat}=	${TOOLS_REAL_CMD.bzcat}
.  endif
.endif

.if !defined(TOOLS_IGNORE.cat) && !empty(_USE_TOOLS:Mcat)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cat=
.  elif !empty(_TOOLS_USE_PKGSRC.cat:M[yY][eE][sS])
TOOLS_DEPENDS.cat?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			cat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.cat=coreutils
TOOLS_REAL_CMD.cat=		${TOOLS_PREFIX.cat}/bin/${GNU_PROGRAM_PREFIX}cat
TOOLS_${_TOOLS_VARNAME.cat}=	${TOOLS_REAL_CMD.cat}
.  endif
.endif

.if !defined(TOOLS_IGNORE.chgrp) && !empty(_USE_TOOLS:Mchgrp)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chgrp=
.  elif !empty(_TOOLS_USE_PKGSRC.chgrp:M[yY][eE][sS])
TOOLS_DEPENDS.chgrp?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			chgrp
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.chgrp=coreutils
TOOLS_REAL_CMD.chgrp=		${TOOLS_PREFIX.chgrp}/bin/${GNU_PROGRAM_PREFIX}chgrp
TOOLS_${_TOOLS_VARNAME.chgrp}=	${TOOLS_REAL_CMD.chgrp}
.  endif
.endif

.if !defined(TOOLS_IGNORE.chmod) && !empty(_USE_TOOLS:Mchmod)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chmod=
.  elif !empty(_TOOLS_USE_PKGSRC.chmod:M[yY][eE][sS])
TOOLS_DEPENDS.chmod?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			chmod
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.chmod=coreutils
TOOLS_REAL_CMD.chmod=		${TOOLS_PREFIX.chmod}/bin/${GNU_PROGRAM_PREFIX}chmod
TOOLS_${_TOOLS_VARNAME.chmod}=	${TOOLS_REAL_CMD.chmod}
.  endif
.endif

.if !defined(TOOLS_IGNORE.chown) && !empty(_USE_TOOLS:Mchown)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.chown=
.  elif !empty(_TOOLS_USE_PKGSRC.chown:M[yY][eE][sS])
TOOLS_DEPENDS.chown?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			chown
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.chown=coreutils
TOOLS_REAL_CMD.chown=		${TOOLS_PREFIX.chown}/bin/${GNU_PROGRAM_PREFIX}chown
TOOLS_${_TOOLS_VARNAME.chown}=	${TOOLS_REAL_CMD.chown}
.  endif
.endif

.if !defined(TOOLS_IGNORE.cmp) && !empty(_USE_TOOLS:Mcmp)
.  if !empty(PKGPATH:Mdevel/diffutils)
MAKEFLAGS+=			TOOLS_IGNORE.cmp=
.  elif !empty(_TOOLS_USE_PKGSRC.cmp:M[yY][eE][sS])
TOOLS_DEPENDS.cmp?=		diffutils>=2.8.1:../../devel/diffutils
TOOLS_CREATE+=			cmp
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.cmp=diffutils
TOOLS_REAL_CMD.cmp=		${TOOLS_PREFIX.cmp}/bin/cmp
TOOLS_${_TOOLS_VARNAME.cmp}=	${TOOLS_REAL_CMD.cmp}
.  endif
.endif

.if !defined(TOOLS_IGNORE.cp) && !empty(_USE_TOOLS:Mcp)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cp=
.  elif !empty(_TOOLS_USE_PKGSRC.cp:M[yY][eE][sS])
TOOLS_DEPENDS.cp?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			cp
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.cp=coreutils
TOOLS_REAL_CMD.cp=		${TOOLS_PREFIX.cp}/bin/${GNU_PROGRAM_PREFIX}cp
TOOLS_${_TOOLS_VARNAME.cp}=	${TOOLS_REAL_CMD.cp}
.  endif
.endif

.if !defined(TOOLS_IGNORE.cut) && !empty(_USE_TOOLS:Mcut)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.cut=
.  elif !empty(_TOOLS_USE_PKGSRC.cut:M[yY][eE][sS])
TOOLS_DEPENDS.cut?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			cut
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.cut=coreutils
TOOLS_REAL_CMD.cut=		${TOOLS_PREFIX.cut}/bin/${GNU_PROGRAM_PREFIX}cut
TOOLS_${_TOOLS_VARNAME.cut}=	${TOOLS_REAL_CMD.cut}
.  endif
.endif

.if !defined(TOOLS_IGNORE.date) && !empty(_USE_TOOLS:Mdate)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.date=
.  elif !empty(_TOOLS_USE_PKGSRC.date:M[yY][eE][sS])
TOOLS_DEPENDS.date?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			date
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.date=coreutils
TOOLS_REAL_CMD.date=		${TOOLS_PREFIX.date}/bin/${GNU_PROGRAM_PREFIX}date
TOOLS_${_TOOLS_VARNAME.date}=	${TOOLS_REAL_CMD.date}
.  endif
.endif

.if !defined(TOOLS_IGNORE.dirname) && !empty(_USE_TOOLS:Mdirname)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.dirname=
.  elif !empty(_TOOLS_USE_PKGSRC.dirname:M[yY][eE][sS])
TOOLS_DEPENDS.dirname?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			dirname
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.dirname=coreutils
TOOLS_REAL_CMD.dirname=		${TOOLS_PREFIX.dirname}/bin/${GNU_PROGRAM_PREFIX}dirname
TOOLS_${_TOOLS_VARNAME.dirname}=	${TOOLS_REAL_CMD.dirname}
.  endif
.endif

.if !defined(TOOLS_IGNORE.echo) && !empty(_USE_TOOLS:Mecho)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.echo=
.  elif !empty(_TOOLS_USE_PKGSRC.echo:M[yY][eE][sS])
TOOLS_DEPENDS.echo?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			echo
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.echo=coreutils
TOOLS_REAL_CMD.echo=		${TOOLS_PREFIX.echo}/bin/${GNU_PROGRAM_PREFIX}echo
TOOLS_${_TOOLS_VARNAME.echo}=	${TOOLS_REAL_CMD.echo}
.  endif
.endif

.if !defined(TOOLS_IGNORE.egrep) && !empty(_USE_TOOLS:Megrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.egrep=
.  elif !empty(_TOOLS_USE_PKGSRC.egrep:M[yY][eE][sS])
TOOLS_DEPENDS.egrep?=		grep>=2.5.1:../../textproc/grep
TOOLS_CREATE+=			egrep
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.egrep=grep
TOOLS_REAL_CMD.egrep=		${TOOLS_PREFIX.egrep}/bin/${GNU_PROGRAM_PREFIX}egrep
TOOLS_${_TOOLS_VARNAME.egrep}=	${TOOLS_REAL_CMD.egrep}
.  endif
.endif

.if !defined(TOOLS_IGNORE.env) && !empty(_USE_TOOLS:Menv)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.env=
.  elif !empty(_TOOLS_USE_PKGSRC.env:M[yY][eE][sS])
TOOLS_DEPENDS.env?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			env
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.env=coreutilsj
TOOLS_REAL_CMD.env=		${TOOLS_PREFIX.env}/bin/${GNU_PROGRAM_PREFIX}env
TOOLS_${_TOOLS_VARNAME.env}=	${TOOLS_REAL_CMD.env}
.  endif
.endif

.if !defined(TOOLS_IGNORE.expr) && !empty(_USE_TOOLS:Mexpr)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.expr=
.  elif !empty(_TOOLS_USE_PKGSRC.expr:M[yY][eE][sS])
TOOLS_DEPENDS.expr?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			expr
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.expr=coreutils
TOOLS_REAL_CMD.expr=		${TOOLS_PREFIX.expr}/bin/${GNU_PROGRAM_PREFIX}expr
TOOLS_${_TOOLS_VARNAME.expr}=	${TOOLS_REAL_CMD.expr}
.  endif
.endif

.if !defined(TOOLS_IGNORE.false) && !empty(_USE_TOOLS:Mfalse)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.false=
.  elif !empty(_TOOLS_USE_PKGSRC.false:M[yY][eE][sS])
TOOLS_DEPENDS.false?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			false
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.false=coreutils
TOOLS_REAL_CMD.false=		${TOOLS_PREFIX.false}/bin/${GNU_PROGRAM_PREFIX}false
TOOLS_${_TOOLS_VARNAME.false}=	${TOOLS_REAL_CMD.false}
.  endif
.endif

.if !defined(TOOLS_IGNORE.fgrep) && !empty(_USE_TOOLS:Mfgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.fgrep=
.  elif !empty(_TOOLS_USE_PKGSRC.fgrep:M[yY][eE][sS])
TOOLS_DEPENDS.fgrep?=		grep>=2.5.1:../../textproc/grep
TOOLS_CREATE+=			fgrep
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.fgrep=grep
TOOLS_REAL_CMD.fgrep=		${TOOLS_PREFIX.fgrep}/bin/${GNU_PROGRAM_PREFIX}fgrep
TOOLS_${_TOOLS_VARNAME.fgrep}=	${TOOLS_REAL_CMD.fgrep}
.  endif
.endif

.if !defined(TOOLS_IGNORE.file) && !empty(_USE_TOOLS:Mfile)
.  if !empty(PKGPATH:Msysutils/file)
MAKEFLAGS+=			TOOLS_IGNORE.file=
.  elif !empty(_TOOLS_USE_PKGSRC.file:M[yY][eE][sS])
TOOLS_DEPENDS.file?=		file>=4.13:../../sysutils/file
TOOLS_CREATE+=			file
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.file=file
TOOLS_REAL_CMD.file=		${TOOLS_PREFIX.file}/bin/file
TOOLS_${_TOOLS_VARNAME.file}=	${TOOLS_REAL_CMD.file}
.  endif
.endif

.if !defined(TOOLS_IGNORE.find) && !empty(_USE_TOOLS:Mfind)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.find=
.  elif !empty(_TOOLS_USE_PKGSRC.find:M[yY][eE][sS])
TOOLS_DEPENDS.find?=		findutils>=4.1:../../sysutils/findutils
TOOLS_CREATE+=			find
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.find=findutils
TOOLS_REAL_CMD.find=		${TOOLS_PREFIX.find}/bin/${GNU_PROGRAM_PREFIX}find
TOOLS_${_TOOLS_VARNAME.find}=	${TOOLS_REAL_CMD.find}
.  endif
.endif

.if !defined(TOOLS_IGNORE.gawk) && !empty(_USE_TOOLS:Mgawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.gawk=
.  elif !empty(_TOOLS_USE_PKGSRC.gawk:M[yY][eE][sS])
TOOLS_DEPENDS.gawk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_CREATE+=			gawk
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gawk=gawk
TOOLS_REAL_CMD.gawk=		${TOOLS_PREFIX.gawk}/bin/${GNU_PROGRAM_PREFIX}awk
TOOLS_${_TOOLS_VARNAME.gawk}=	${TOOLS_REAL_CMD.gawk}
.  endif
TOOLS_ALIASES.gawk=		awk
.endif

.if !defined(TOOLS_IGNORE.gm4) && !empty(_USE_TOOLS:Mgm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.gm4=
.  elif !empty(_TOOLS_USE_PKGSRC.gm4:M[yY][eE][sS])
TOOLS_DEPENDS.gm4?=		m4>=1.4:../../devel/m4
TOOLS_CREATE+=			gm4
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gm4=m4
TOOLS_REAL_CMD.gm4=		${TOOLS_PREFIX.gm4}/bin/gm4
TOOLS_${_TOOLS_VARNAME.gm4}=	${TOOLS_REAL_CMD.gm4}
.  endif
TOOLS_ALIASES.gm4=		m4
.endif

.if !defined(TOOLS_IGNORE.gmake) && !empty(_USE_TOOLS:Mgmake)
.  if !empty(PKGPATH:Mdevel/gmake)
MAKEFLAGS+=			TOOLS_IGNORE.gmake=
.  elif !empty(_TOOLS_USE_PKGSRC.gmake:M[yY][eE][sS])
TOOLS_DEPENDS.gmake?=		gmake>=3.78:../../devel/gmake
TOOLS_CREATE+=			gmake
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gmake=gmake
TOOLS_REAL_CMD.gmake=		${TOOLS_PREFIX.gmake}/bin/gmake
TOOLS_${_TOOLS_VARNAME.gmake}=	${TOOLS_REAL_CMD.gmake}
.  endif
.endif

.if !defined(TOOLS_IGNORE.grep) && !empty(_USE_TOOLS:Mgrep)
.  if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=			TOOLS_IGNORE.grep=
.  elif !empty(_TOOLS_USE_PKGSRC.grep:M[yY][eE][sS])
TOOLS_DEPENDS.grep?=		grep>=2.5.1:../../textproc/grep
TOOLS_CREATE+=			grep
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.grep=grep
TOOLS_REAL_CMD.grep=		${TOOLS_PREFIX.grep}/bin/${GNU_PROGRAM_PREFIX}grep
TOOLS_${_TOOLS_VARNAME.grep}=	${TOOLS_REAL_CMD.grep}
.  endif
.endif

.if !defined(TOOLS_IGNORE.gsed) && !empty(_USE_TOOLS:Mgsed)
.  if !empty(PKGPATH:Mtextproc/gsed)
MAKEFLAGS+=			TOOLS_IGNORE.gsed=
.  elif !empty(_TOOLS_USE_PKGSRC.gsed:M[yY][eE][sS])
TOOLS_DEPENDS.gsed?=		gsed>=3.0.2:../../textproc/gsed
TOOLS_CREATE+=			gsed
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gsed=gsed
TOOLS_REAL_CMD.gsed=		${TOOLS_PREFIX.gsed}/bin/${GNU_PROGRAM_PREFIX}sed
TOOLS_${_TOOLS_VARNAME.gsed}=	${TOOLS_REAL_CMD.gsed}
.  endif
TOOLS_ALIASES.gsed=		sed
.endif

.if !defined(TOOLS_IGNORE.gtar) && !empty(_USE_TOOLS:Mgtar)
.  if !empty(PKGPATH:Marchivers/gtar-base)
MAKEFLAGS+=			TOOLS_IGNORE.gtar=
.  elif !empty(_TOOLS_USE_PKGSRC.gtar:M[yY][eE][sS])
TOOLS_DEPENDS.gtar?=		gtar-base>=1.13.25:../../archivers/gtar-base
TOOLS_CREATE+=			gtar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gtar=gtar-base
TOOLS_REAL_CMD.gtar=		${TOOLS_PREFIX.gtar}/bin/${GNU_PROGRAM_PREFIX}tar
TOOLS_${_TOOLS_VARNAME.gtar}=	${TOOLS_REAL_CMD.gtar}
.  endif
#
# The most likely situation is that "gtar" is pax-as-tar, and older
# versions of it don't understand what to do if they're invoked as
# "gtar".  Explicitly set TOOLS_REAL_CMDLINE.gtar to force a wrapper
# script to be created.
#
TOOLS_REAL_CMDLINE.gtar?=	${TOOLS_REAL_CMDLINE_DFLT.gtar}
.endif

.if !defined(TOOLS_IGNORE.gunzip) && !empty(_USE_TOOLS:Mgunzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gunzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gunzip:M[yY][eE][sS])
TOOLS_DEPENDS.gunzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gunzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gunzip=gzip-base
TOOLS_REAL_CMD.gunzip=		${TOOLS_PREFIX.gunzip}/bin/gunzip
TOOLS_REAL_ARGS.gunzip=		-f
TOOLS_${_TOOLS_VARNAME.gunzip}=	${TOOLS_REAL_CMD.gunzip} ${TOOLS_REAL_ARGS.gunzip}
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzcat) && !empty(_USE_TOOLS:Mgzcat)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.gzcat:M[yY][eE][sS])
TOOLS_DEPENDS.gzcat?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzcat=gzip-base
TOOLS_REAL_CMD.gzcat=		${TOOLS_PREFIX.gzcat}/bin/gzcat
TOOLS_${_TOOLS_VARNAME.gzcat}=	${TOOLS_REAL_CMD.gzcat}
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzip) && !empty(_USE_TOOLS:Mgzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gzip:M[yY][eE][sS])
TOOLS_DEPENDS.gzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzip=gzip-base
TOOLS_REAL_CMD.gzip=		${TOOLS_PREFIX.gzip}/bin/gzip
TOOLS_REAL_ARGS.gzip=		-nf ${GZIP}
TOOLS_${_TOOLS_VARNAME.gzip}=	${TOOLS_REAL_CMD.gzip} ${TOOLS_REAL_ARGS.gzip}
.  endif
.endif

.if !defined(TOOLS_IGNORE.head) && !empty(_USE_TOOLS:Mhead)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.head=
.  elif !empty(_TOOLS_USE_PKGSRC.head:M[yY][eE][sS])
TOOLS_DEPENDS.head?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			head
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.head=coreutils
TOOLS_REAL_CMD.head=		${TOOLS_PREFIX.head}/bin/${GNU_PROGRAM_PREFIX}head
TOOLS_${_TOOLS_VARNAME.head}=	${TOOLS_REAL_CMD.head}
.  endif
.endif

.if !defined(TOOLS_IGNORE.hostname) && !empty(_USE_TOOLS:Mhostname)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.hostname=
.  elif !empty(_TOOLS_USE_PKGSRC.hostname:M[yY][eE][sS])
TOOLS_DEPENDS.hostname?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			hostname
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.hostname=coreutils
TOOLS_REAL_CMD.hostname=	${TOOLS_PREFIX.hostname}/bin/${GNU_PROGRAM_PREFIX}hostname
TOOLS_${_TOOLS_VARNAME.hostname}=	${TOOLS_REAL_CMD.hostname}
.  endif
.endif

.if !defined(TOOLS_IGNORE.id) && !empty(_USE_TOOLS:Mid)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.id=
.  elif !empty(_TOOLS_USE_PKGSRC.id:M[yY][eE][sS])
TOOLS_DEPENDS.id?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			id
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.id=coreutils
TOOLS_REAL_CMD.id=		${TOOLS_PREFIX.id}/bin/${GNU_PROGRAM_PREFIX}id
TOOLS_${_TOOLS_VARNAME.id}=	${TOOLS_REAL_CMD.id}
.  endif
.endif

.if !defined(TOOLS_IGNORE.install) && !empty(_USE_TOOLS:Minstall)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.install=
.  elif !empty(_TOOLS_USE_PKGSRC.install:M[yY][eE][sS])
TOOLS_DEPENDS.install?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			install
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.install=coreutils
TOOLS_REAL_CMD.install=		${TOOLS_PREFIX.install}/bin/${GNU_PROGRAM_PREFIX}install
TOOLS_${_TOOLS_VARNAME.install}=	${TOOLS_REAL_CMD.install}
.  endif
.endif

.if !defined(TOOLS_IGNORE.lex) && !empty(_USE_TOOLS:Mlex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.lex=
.  elif !empty(_TOOLS_USE_PKGSRC.lex:M[yY][eE][sS])
.    include "../../devel/flex/buildlink3.mk"
_TOOLS_DEPENDS.lex=		# empty
.      for _dep_ in ${BUILDLINK_DEPENDS.flex}
_TOOLS_DEPENDS.lex+=		${_dep_}:${BUILDLINK_PKGSRCDIR.flex}
.      endfor
.      undef _dep_
TOOLS_DEPENDS.lex?=		${_TOOLS_DEPENDS.lex}
TOOLS_CREATE+=			lex
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lex=flex
TOOLS_REAL_CMD.lex=		${TOOLS_PREFIX.lex}/bin/flex
TOOLS_${_TOOLS_VARNAME.lex}=	${TOOLS_REAL_CMD.lex}
.  endif
.endif

.if !defined(TOOLS_IGNORE.lha) && !empty(_USE_TOOLS:Mlha)
.  if !empty(PKGPATH:Marchivers/lha)
MAKEFLAGS+=			TOOLS_IGNORE.lha=
.  elif !empty(_TOOLS_USE_PKGSRC.lha:M[yY][eE][sS])
TOOLS_DEPENDS.lha?=		lha>=114.9:../../archivers/lha
TOOLS_CREATE+=			lha
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lha=lha
TOOLS_REAL_CMD.lha=		${TOOLS_PREFIX.lha}/bin/lha
TOOLS_${_TOOLS_VARNAME.lha}=	${TOOLS_REAL_CMD.lha}
.  endif
.endif

.if !defined(TOOLS_IGNORE.ln) && !empty(_USE_TOOLS:Mln)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.ln=
.  elif !empty(_TOOLS_USE_PKGSRC.ln:M[yY][eE][sS])
TOOLS_DEPENDS.ln?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			ln
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ln=coreutils
TOOLS_REAL_CMD.ln=		${TOOLS_PREFIX.ln}/bin/${GNU_PROGRAM_PREFIX}ln
TOOLS_${_TOOLS_VARNAME.ln}=	${TOOLS_REAL_CMD.ln}
.  endif
.endif

.if !defined(TOOLS_IGNORE.ls) && !empty(_USE_TOOLS:Mls)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.ls=
.  elif !empty(_TOOLS_USE_PKGSRC.ls:M[yY][eE][sS])
TOOLS_DEPENDS.ls?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			ls
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ls=coreutils
TOOLS_REAL_CMD.ls=		${TOOLS_PREFIX.ls}/bin/${GNU_PROGRAM_PREFIX}ls
TOOLS_${_TOOLS_VARNAME.ls}=	${TOOLS_REAL_CMD.ls}
.  endif
.endif

.if !defined(TOOLS_IGNORE.m4) && !empty(_USE_TOOLS:Mm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.m4=
.  elif !empty(_TOOLS_USE_PKGSRC.m4:M[yY][eE][sS])
TOOLS_DEPENDS.m4?=		m4>=1.4:../../devel/m4
TOOLS_CREATE+=			m4
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.m4=m4
TOOLS_REAL_CMD.m4=		${TOOLS_PREFIX.m4}/bin/gm4
TOOLS_${_TOOLS_VARNAME.m4}=	${TOOLS_REAL_CMD.m4}
.  endif
.endif

.if !defined(TOOLS_IGNORE.mail) && !empty(_USE_TOOLS:Mmail)
.  if !empty(PKGPATH:Mmail/nail)
MAKEFLAGS+=			TOOLS_IGNORE.mail=
.  elif !empty(_TOOLS_USE_PKGSRC.mail:M[yY][eE][sS])
TOOLS_DEPENDS.mail?=		nail>=11.22:../../mail/nail
TOOLS_CREATE+=			mail
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mail=nail
TOOLS_REAL_CMD.mail=		${TOOLS_PREFIX.mail}/bin/nail
TOOLS_${_TOOLS_VARNAME.mail}=	${TOOLS_REAL_CMD.mail}
.  endif
.endif

.if !defined(TOOLS_IGNORE.mkdir) && !empty(_USE_TOOLS:Mmkdir)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.mkdir=
.  elif !empty(_TOOLS_USE_PKGSRC.mkdir:M[yY][eE][sS])
TOOLS_DEPENDS.mkdir?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			mkdir
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mkdir=coreutils
TOOLS_REAL_CMD.mkdir=		${TOOLS_PREFIX.mkdir}/bin/${GNU_PROGRAM_PREFIX}mkdir
TOOLS_REAL_ARGS.mkdir=		-p
TOOLS_${_TOOLS_VARNAME.mkdir}=	${TOOLS_REAL_CMD.mkdir} ${TOOLS_REAL_ARGS.mkdir}
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
TOOLS_CREATE+=			mtree
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mtree=mtree
TOOLS_REAL_CMD.mtree=		${TOOLS_PREFIX.mtree}/bin/mtree
TOOLS_${_TOOLS_VARNAME.mtree}=	${TOOLS_REAL_CMD.mtree}
.  endif
.endif

.if !defined(TOOLS_IGNORE.mv) && !empty(_USE_TOOLS:Mmv)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.mv=
.  elif !empty(_TOOLS_USE_PKGSRC.mv:M[yY][eE][sS])
TOOLS_DEPENDS.mv?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			mv
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mv=coreutils
TOOLS_REAL_CMD.mv=		${TOOLS_PREFIX.mv}/bin/${GNU_PROGRAM_PREFIX}mv
TOOLS_${_TOOLS_VARNAME.mv}=	${TOOLS_REAL_CMD.mv}
.  endif
.endif

.if !defined(TOOLS_IGNORE.nice) && !empty(_USE_TOOLS:Mnice)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.nice=
.  elif !empty(_TOOLS_USE_PKGSRC.nice:M[yY][eE][sS])
TOOLS_DEPENDS.nice?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			nice
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.nice=coreutils
TOOLS_REAL_CMD.nice=		${TOOLS_PREFIX.nice}/bin/${GNU_PROGRAM_PREFIX}nice
TOOLS_${_TOOLS_VARNAME.nice}=	${TOOLS_REAL_CMD.nice}
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(_USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  elif !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
TOOLS_DEPENDS.patch?=		patch>=2.2:../../devel/patch
TOOLS_CREATE+=			patch
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.patch=patch
TOOLS_REAL_CMD.patch=		${TOOLS_PREFIX.patch}/bin/gpatch
TOOLS_${_TOOLS_VARNAME.patch}=	${TOOLS_REAL_CMD.patch}
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
TOOLS_CREATE+=			pax
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pax=pax
TOOLS_REAL_CMD.pax=		${TOOLS_PREFIX.pax}/bin/pax
TOOLS_${_TOOLS_VARNAME.pax}=	${TOOLS_REAL_CMD.pax}
.  endif
.endif

.if !defined(TOOLS_IGNORE.pwd) && !empty(_USE_TOOLS:Mpwd)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.pwd=
.  elif !empty(_TOOLS_USE_PKGSRC.pwd:M[yY][eE][sS])
TOOLS_DEPENDS.pwd?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			pwd
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pwd=coreutils
TOOLS_REAL_CMD.pwd=		${TOOLS_PREFIX.pwd}/bin/${GNU_PROGRAM_PREFIX}pwd
TOOLS_${_TOOLS_VARNAME.pwd}=	${TOOLS_REAL_CMD.pwd}
.  endif
.endif

.if !defined(TOOLS_IGNORE.rm) && !empty(_USE_TOOLS:Mrm)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.rm=
.  elif !empty(_TOOLS_USE_PKGSRC.rm:M[yY][eE][sS])
TOOLS_DEPENDS.rm?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			rm
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.rm=coreutils
TOOLS_REAL_CMD.rm=		${TOOLS_PREFIX.rm}/bin/${GNU_PROGRAM_PREFIX}rm
TOOLS_${_TOOLS_VARNAME.rm}=	${TOOLS_REAL_CMD.rm}
.  endif
.endif

.if !defined(TOOLS_IGNORE.rmdir) && !empty(_USE_TOOLS:Mrmdir)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.rmdir=
.  elif !empty(_TOOLS_USE_PKGSRC.rmdir:M[yY][eE][sS])
TOOLS_DEPENDS.rmdir?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			rmdir
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.rmdir=coreutils
TOOLS_REAL_CMD.rmdir=		${TOOLS_PREFIX.rmdir}/bin/${GNU_PROGRAM_PREFIX}rmdir
TOOLS_${_TOOLS_VARNAME.rmdir}=	${TOOLS_REAL_CMD.rmdir}
.  endif
.endif

.if !defined(TOOLS_IGNORE.sed) && !empty(_USE_TOOLS:Msed)
.  if !empty(PKGPATH:Mtextproc/nbsed)
MAKEFLAGS+=			TOOLS_IGNORE.sed=
.  elif !empty(_TOOLS_USE_PKGSRC.sed:M[yY][eE][sS])
TOOLS_DEPENDS.sed?=		nbsed>=20040821:../../textproc/nbsed
TOOLS_CREATE+=			sed
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.sed=nbsed
TOOLS_REAL_CMD.sed=		${TOOLS_PREFIX.nbsed}/bin/nbsed
TOOLS_${_TOOLS_VARNAME.sed}=	${TOOLS_REAL_CMD.sed}
.  endif
.endif

.if !defined(TOOLS_IGNORE.sh) && !empty(_USE_TOOLS:Msh)
.  if !empty(PKGPATH:Mshells/pdksh)
MAKEFLAGS+=			TOOLS_IGNORE.sh=
.  elif !empty(_TOOLS_USE_PKGSRC.sh:M[yY][eE][sS])
TOOLS_DEPENDS.sh?=		pdksh>=5.2.14:../../shells/pdksh
TOOLS_CREATE+=			sh
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.sh=pdksh
TOOLS_REAL_CMD.sh=		${TOOLS_PREFIX.sh}/bin/pdksh
TOOLS_${_TOOLS_VARNAME.sh}=	${TOOLS_REAL_CMD.sh}
.  endif
TOOLS_CMD.sh=			${TOOLS_DIR}/bin/sh
.endif

.if !defined(TOOLS_IGNORE.shlock) && !empty(_USE_TOOLS:Mshlock)
.  if !empty(PKGPATH:Mpkgtools/shlock)
MAKEFLAGS+=			TOOLS_IGNORE.shlock=
.  elif !empty(_TOOLS_USE_PKGSRC.shlock:M[yY][eE][sS])
TOOLS_DEPENDS.shlock?=		shlock>=20020114:../../pkgtools/shlock
TOOLS_CREATE+=			shlock
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.shlock=shlock
TOOLS_REAL_CMD.shlock=		${TOOLS_PREFIX.shlock}/bin/shlock
TOOLS_${_TOOLS_VARNAME.shlock}=	${TOOLS_REAL_CMD.shlock}
.  endif
.endif

.if !defined(TOOLS_IGNORE.sort) && !empty(_USE_TOOLS:Msort)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.sort=
.  elif !empty(_TOOLS_USE_PKGSRC.sort:M[yY][eE][sS])
TOOLS_DEPENDS.sort?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			sort
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.sort=coreutils
TOOLS_REAL_CMD.sort=		${TOOLS_PREFIX.sort}/bin/${GNU_PROGRAM_PREFIX}sort
TOOLS_${_TOOLS_VARNAME.sort}=	${TOOLS_REAL_CMD.sort}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tail) && !empty(_USE_TOOLS:Mtail)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tail=
.  elif !empty(_TOOLS_USE_PKGSRC.tail:M[yY][eE][sS])
TOOLS_DEPENDS.tail?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			tail
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tail=coreutils
TOOLS_REAL_CMD.tail=		${TOOLS_PREFIX.tail}/bin/${GNU_PROGRAM_PREFIX}tail
TOOLS_${_TOOLS_VARNAME.tail}=	${TOOLS_REAL_CMD.tail}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tar) && !empty(_USE_TOOLS:Mtar)
.  if !empty(PKGPATH:Marchivers/pax)
MAKEFLAGS+=			TOOLS_IGNORE.tar=
.  elif !empty(_TOOLS_USE_PKGSRC.tar:M[yY][eE][sS])
#
# This is installed by pkgsrc bootstrap, and is never registered, so
# comment out the dependency on it.
#
#TOOLS_DEPENDS.tar?=		pax>=20040802:../../archivers/pax
TOOLS_CREATE+=			tar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tar=pax
TOOLS_REAL_CMD.tar=		${TOOLS_PREFIX.tar}/bin/tar
TOOLS_${_TOOLS_VARNAME.tar}=	${TOOLS_REAL_CMD.tar}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tbl) && !empty(_USE_TOOLS:Mtbl)
.  if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=			TOOLS_IGNORE.tbl=
.  elif !empty(_TOOLS_USE_PKGSRC.tbl:M[yY][eE][sS])
TOOLS_DEPENDS.tbl?=		groff>=1.19nb4:../../textproc/groff
TOOLS_CREATE+=			tbl
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tbl=groff
TOOLS_REAL_CMD.tbl=		${TOOLS_PREFIX.tbl}/bin/tbl
TOOLS_${_TOOLS_VARNAME.tbl}=	${TOOLS_REAL_CMD.tbl}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tee) && !empty(_USE_TOOLS:Mtee)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tee=
.  elif !empty(_TOOLS_USE_PKGSRC.tee:M[yY][eE][sS])
TOOLS_DEPENDS.tee?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			tee
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tee=coreutils
TOOLS_REAL_CMD.tee=		${TOOLS_PREFIX.tee}/bin/${GNU_PROGRAM_PREFIX}tee
TOOLS_${_TOOLS_VARNAME.tee}=	${TOOLS_REAL_CMD.tee}
.  endif
.endif

.if !defined(TOOLS_IGNORE.test) && !empty(_USE_TOOLS:Mtest)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.test=
.  elif !empty(_TOOLS_USE_PKGSRC.test:M[yY][eE][sS])
TOOLS_DEPENDS.test?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			test
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.test=coreutils
TOOLS_REAL_CMD.test=		${TOOLS_PREFIX.test}/bin/${GNU_PROGRAM_PREFIX}test
TOOLS_${_TOOLS_VARNAME.test}=	${TOOLS_REAL_CMD.test}
.  endif
.endif

.if !defined(TOOLS_IGNORE.touch) && !empty(_USE_TOOLS:Mtouch)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.touch=
.  elif !empty(_TOOLS_USE_PKGSRC.touch:M[yY][eE][sS])
TOOLS_DEPENDS.touch?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			touch
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.touch=coreutils
TOOLS_REAL_CMD.touch=		${TOOLS_PREFIX.touch}/bin/${GNU_PROGRAM_PREFIX}touch
TOOLS_${_TOOLS_VARNAME.touch}=	${TOOLS_REAL_CMD.touch}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tr) && !empty(_USE_TOOLS:Mtr)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tr=
.  elif !empty(_TOOLS_USE_PKGSRC.tr:M[yY][eE][sS])
TOOLS_DEPENDS.tr?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			tr
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tr=coreutils
TOOLS_REAL_CMD.tr=		${TOOLS_PREFIX.tr}/bin/${GNU_PROGRAM_PREFIX}tr
TOOLS_${_TOOLS_VARNAME.tr}=	${TOOLS_REAL_CMD.tr}
.  endif
.endif

.if !defined(TOOLS_IGNORE.true) && !empty(_USE_TOOLS:Mtrue)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.true=
.  elif !empty(_TOOLS_USE_PKGSRC.true:M[yY][eE][sS])
TOOLS_DEPENDS.true?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			true
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.true=coreutils
TOOLS_REAL_CMD.true=		${TOOLS_PREFIX.true}/bin/${GNU_PROGRAM_PREFIX}true
TOOLS_${_TOOLS_VARNAME.true}=	${TOOLS_REAL_CMD.true}
.  endif
.endif

.if !defined(TOOLS_IGNORE.tsort) && !empty(_USE_TOOLS:Mtsort)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.tsort=
.  elif !empty(_TOOLS_USE_PKGSRC.tsort:M[yY][eE][sS])
TOOLS_DEPENDS.tsort?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			tsort
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tsort=coreutils
TOOLS_REAL_CMD.tsort=		${TOOLS_PREFIX.tsort}/bin/${GNU_PROGRAM_PREFIX}tsort
TOOLS_${_TOOLS_VARNAME.tsort}=	${TOOLS_REAL_CMD.tsort}
.  endif
.endif

.if !defined(TOOLS_IGNORE.unrar) && !empty(_USE_TOOLS:Munrar)
.  if !empty(PKGPATH:Marchivers/unrar)
MAKEFLAGS+=			TOOLS_IGNORE.unrar=
.  elif !empty(_TOOLS_USE_PKGSRC.unrar:M[yY][eE][sS])
TOOLS_DEPENDS.unrar?=		unrar>=3.3.4:../../archivers/unrar
TOOLS_CREATE+=			unrar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unrar=unrar
TOOLS_REAL_CMD.unrar=		${TOOLS_PREFIX.unrar}/bin/unrar
TOOLS_${_TOOLS_VARNAME.unrar}=	${TOOLS_REAL_CMD.unrar}
.  endif
.endif

.if !defined(TOOLS_IGNORE.unzip) && !empty(_USE_TOOLS:Munzip)
.  if !empty(PKGPATH:Marchivers/unzip)
MAKEFLAGS+=			TOOLS_IGNORE.unzip=
.  elif !empty(_TOOLS_USE_PKGSRC.unzip:M[yY][eE][sS])
TOOLS_DEPENDS.unzip?=		unzip-[0-9]*:../../archivers/unzip
TOOLS_CREATE+=			unzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unzip=unzip
TOOLS_REAL_CMD.unzip=		${TOOLS_PREFIX.unzip}/bin/unzip
TOOLS_${_TOOLS_VARNAME.unzip}=	${TOOLS_REAL_CMD.unzip}
.  endif
.endif

.if !defined(TOOLS_IGNORE.unzoo) && !empty(_USE_TOOLS:Munzoo)
.  if !empty(PKGPATH:Marchivers/unzoo)
MAKEFLAGS+=			TOOLS_IGNORE.unzoo=
.  elif !empty(_TOOLS_USE_PKGSRC.unzoo:M[yY][eE][sS])
TOOLS_DEPENDS.unzoo?=		unzoo-[0-9]*:../../archivers/unzoo
TOOLS_CREATE+=			unzoo
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unzoo=unzoo
TOOLS_REAL_CMD.unzoo=		${TOOLS_PREFIX.unzoo}/bin/unzoo
TOOLS_${_TOOLS_VARNAME.unzoo}=	${TOOLS_REAL_CMD.unzoo}
.  endif
.endif

.if !defined(TOOLS_IGNORE.wc) && !empty(_USE_TOOLS:Mwc)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=			TOOLS_IGNORE.wc=
.  elif !empty(_TOOLS_USE_PKGSRC.wc:M[yY][eE][sS])
TOOLS_DEPENDS.wc?=		coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=			wc
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.wc=coreutils
TOOLS_REAL_CMD.wc=		${TOOLS_PREFIX.wc}/bin/${GNU_PROGRAM_PREFIX}wc
TOOLS_${_TOOLS_VARNAME.wc}=	${TOOLS_REAL_CMD.wc}
.  endif
.endif

.if !defined(TOOLS_IGNORE.xargs) && !empty(_USE_TOOLS:Mxargs)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.xargs=
.  elif !empty(_TOOLS_USE_PKGSRC.xargs:M[yY][eE][sS])
TOOLS_DEPENDS.xargs?=		findutils>=4.1:../../sysutils/findutils
TOOLS_CREATE+=			xargs
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.xargs=findutils
TOOLS_REAL_CMD.xargs=		${TOOLS_PREFIX.xargs}/bin/${GNU_PROGRAM_PREFIX}xargs
TOOLS_REAL_ARGS.xargs=		-r	# don't run command if stdin is empty
TOOLS_${_TOOLS_VARNAME.xargs}=	${TOOLS_REAL_CMD.xargs} ${TOOLS_REAL_ARGS.xargs}
.  endif
.endif

.if !defined(TOOLS_IGNORE.yacc) && !empty(_USE_TOOLS:Myacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.yacc=
.  elif !empty(_TOOLS_USE_PKGSRC.yacc:M[yY][eE][sS])
TOOLS_DEPENDS.yacc?=		bison>=1.0:../../devel/bison
TOOLS_CREATE+=			yacc
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.yacc=bison
TOOLS_REAL_CMD.yacc=		${TOOLS_PREFIX.yacc}/bin/bison
TOOLS_REAL_ARGS.yacc=		-y
TOOLS_${_TOOLS_VARNAME.yacc}=	${TOOLS_REAL_CMD.yacc} ${TOOLS_REAL_ARGS.yacc}
.  endif
.endif

# Compute the locations of the pkgsrc-supplied tools.
FIND_PREFIX:=	${TOOLS_FIND_PREFIX}
.include "../../mk/find-prefix.mk"

######################################################################

# Add the dependencies for each pkgsrc-supplied tool.
#
.for _t_ in ${_USE_TOOLS}
.  if defined(TOOLS_DEPMETHOD.${_t_}) && defined(TOOLS_DEPENDS.${_t_})
.    if empty(${TOOLS_DEPMETHOD.${_t_}}:M${TOOLS_DEPENDS.${_t_}})
${TOOLS_DEPMETHOD.${_t_}}+=	${TOOLS_DEPENDS.${_t_}}
.    endif
.  endif
.endfor

######################################################################

# For each tool that pkgsrc requires, make sure that the "TOOL" name
# points to the real command, e.g., AWK, SED, etc., provided that
# "TOOL" has been associated with <tool>.
#
.for _t_ in ${PKGSRC_USE_TOOLS:O:u}
_TOOLS_USE_PKGSRC.${_t_}?=	no
.  if defined(_TOOLS_VARNAME.${_t_})
.    if !empty(_TOOLS_USE_PKGSRC.${_t_}:M[nN][oO])
.      if defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_PLATFORM.${_t_}}
.      endif
.    else
${_TOOLS_VARNAME.${_t_}}=	${TOOLS_${_TOOLS_VARNAME.${_t_}}}
.    endif
.  endif
.endfor
.undef _t_

######################################################################

# If we are using the system-supplied tool, create symlinks or wrappers
# for each of the tools requested.
#
# Set TOOLS_REAL_CMD.<tool> appropriately in the case where we are
# using the system-supplied tool.  Here, we first check to see if
# TOOLS_PLATFORM.<tool> is defined.  If it is, then use that as the
# path to the real command and extract any arguments into
# TOOLS_REAL_ARGS.<tool>.
#
# Always set the "TOOLS_TOOL" name for each tool to point to the real
# command, e.g., TOOLS_TBL, TOOLS_YACC, etc., provided that "TOOL" has
# been associated with <tool>.  If the "TOOL" name is undefined, then
# set it to the same value to provide a simple name for use by package
# Makefiles.
#
.for _t_ in ${_USE_TOOLS}
.  if !defined(TOOLS_IGNORE.${_t_}) && \
      !empty(_TOOLS_USE_PKGSRC.${_t_}:M[nN][oO])
.    if defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
TOOLS_REAL_CMD.${_t_}?=		\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_REAL_ARGS.${_t_}?=	\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:N_asdf_*}
.      if defined(_TOOLS_VARNAME.${_t_})
TOOLS_${_TOOLS_VARNAME.${_t_}}=	${TOOLS_PLATFORM.${_t_}}
.      endif
TOOLS_CREATE+=			${_t_}
.    elif defined(_TOOLS_VARNAME.${_t_})
.      if defined(TOOLS_REAL_CMD.${_t_})
TOOLS_${_TOOLS_VARNAME.${_t_}}=	${TOOLS_REAL_CMD.${_t_}} ${TOOLS_REAL_ARGS.${_t_}}
.      else
TOOLS_${_TOOLS_VARNAME.${_t_}}=	${_TOOLS_VARNAME.${_t_}}_not_defined_
.      endif
.    endif
.  endif
.  if defined(_TOOLS_VARNAME.${_t_})
.    if defined(TOOLS_${_TOOLS_VARNAME.${_t_}})
.      for _v_ in ${_TOOLS_VARNAME.${_t_}}
${_v_}?=	${TOOLS_${_TOOLS_VARNAME.${_t_}}}
.      endfor
.      undef _v_
.    endif
.  endif
.endfor
.undef _t_
