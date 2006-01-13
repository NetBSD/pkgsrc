# $NetBSD: replace.mk,v 1.145.2.1 2006/01/13 01:01:00 salo Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

#
# This Makefile fragment handles "replacements" of system-supplied
# tools with pkgsrc versions.
#
# The replacement tools are placed under ${TOOLS_DIR} so that they
# appear earlier in the search path when invoked using the bare name
# of the tool.
#
# "TOOLS_TOOLS" variables, e.g. TOOLS_AWK, TOOLS_SED, etc. are set to
# the full paths to the real tools on the filesystem, and represent
# tools required by the package.
#
# "TOOLS_CMDLINE_TOOL" variables, e.g. TOOLS_CMDLINE_AWK,
# TOOLS_CMDLINE_SED, etc. are set to the full command lines (path and
# arguments) necessary to invoke the real tools on the filesystem
#
# "TOOL" variables, e.g. AWK, SED, etc. are set to the full command
# lines necessary to invoke the real tools on the filesystem, and
# represent the tools required by pkgsrc itself.
#
# The tools that could be replaced with pkgsrc counterparts (usually
# GNU versions of the tools) that are required by pkgsrc itself, i.e.
# in targets that are part of pkgsrc infrastructure or part of the
# package Makefile, or by the package itself, i.e. within the
# software's own build system, should be listed as:
#
#	USE_TOOLS+=	awk gmake lex sed
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
# but this may be changed by adding a :run modifier to the tool name,
# e.g.:
#
#	USE_TOOLS+=	perl:run
#

# XXX Keep this hack here until the day that msgfmt and msgfmt-plurals
# XXX is handled directly by the tools framework.
# XXX
.if defined(USE_MSGFMT_PLURALS) && !empty(USE_MSGFMT_PLURALS:M[yY][eE][sS])
USE_TOOLS+=	perl
.endif

# bison implies "bison-yacc"
.if !empty(USE_TOOLS:Mbison) || !empty(USE_TOOLS:Mbison\:*)
USE_TOOLS+=	bison-yacc
.endif

######################################################################

# Create _USE_TOOLS, a sanitized version of USE_TOOLS that removes the
# ones that are overridden by superseding ones.
#
.if !defined(_USE_TOOLS)
.  for _t_ in ${USE_TOOLS:C/:.*//:O:u}
_USE_TOOLS+=	${_t_}
.  endfor
.  if !empty(_USE_TOOLS:Mbison-yacc)	# bison-yacc > yacc
_USE_TOOLS:=	${_USE_TOOLS:Nyacc}
.  endif
.  if !empty(_USE_TOOLS:Mbyacc)		# byacc > yacc
_USE_TOOLS:=	${_USE_TOOLS:Nyacc}
.  endif
.  if !empty(_USE_TOOLS:Mflex)		# flex > lex
_USE_TOOLS:=	${_USE_TOOLS:Nlex}
.  endif
.  if !empty(_USE_TOOLS:Mgawk)		# gawk > awk
_USE_TOOLS:=	${_USE_TOOLS:Nawk}
.  endif
.  if !empty(_USE_TOOLS:Mgm4)		# gm4 > m4
_USE_TOOLS:=	${_USE_TOOLS:Nm4}
.  endif
.  if !empty(_USE_TOOLS:Mgsed)		# gsed > sed
_USE_TOOLS:=	${_USE_TOOLS:Nsed}
.  endif
.  if !empty(_USE_TOOLS:Mgsoelim)	# gsoelim > soelim
_USE_TOOLS:=	${_USE_TOOLS:Nsoelim}
.  endif
.endif
MAKEVARS+=	_USE_TOOLS

# Catch conflicting tools.
.if !empty(_USE_TOOLS:Mbison) && !empty(_USE_TOOLS:Mbyacc)
PKG_FAIL_REASON+=	"\`\`bison'' and \`\`byacc'' conflict in USE_TOOLS."
.endif

######################################################################

# Set the type of dependency requested for the tool.  The type of
# dependency is determined by the modifier specified for each tool:
#
#    BUILD_DEPENDS:	:build (default), :pkgsrc
#    DEPENDS:		:run
#
.for _t_ in ${USE_TOOLS:N*\:*} ${USE_TOOLS:M*\:build} ${USE_TOOLS:M*\:pkgsrc}
_TOOLS_DEPMETHOD.${_t_:C/:.*//}=	BUILD_DEPENDS
.endfor
.for _t_ in ${USE_TOOLS:M*\:run}
_TOOLS_DEPMETHOD.${_t_:C/:.*//}=	DEPENDS
.endfor

.if !empty(_USE_TOOLS:Mbison-yacc)	# bison-yacc > yacc
.  if (${_TOOLS_DEPMETHOD.bison-yacc} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.yacc)
_TOOLS_DEPMETHOD.bison-yacc=	${_TOOLS_DEPMETHOD.yacc}
.  endif
.endif
.if !empty(_USE_TOOLS:Mflex)		# flex > lex
.  if (${_TOOLS_DEPMETHOD.flex} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.lex)
_TOOLS_DEPMETHOD.flex=		${_TOOLS_DEPMETHOD.lex}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgawk)		# gawk > awk
.  if (${_TOOLS_DEPMETHOD.gawk} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.awk)
_TOOLS_DEPMETHOD.gawk=		${_TOOLS_DEPMETHOD.awk}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgm4)		# gm4 > m4
.  if (${_TOOLS_DEPMETHOD.gm4} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.m4)
_TOOLS_DEPMETHOD.gm4=		${_TOOLS_DEPMETHOD.m4}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgsed)		# gsed > sed
.  if (${_TOOLS_DEPMETHOD.gsed} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.sed)
_TOOLS_DEPMETHOD.gsed=		${_TOOLS_DEPMETHOD.sed}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgsoelim)		# gsoelim > soelim
.  if (${_TOOLS_DEPMETHOD.gsoelim} == "BUILD_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.soelim)
_TOOLS_DEPMETHOD.gsoelim=	${_TOOLS_DEPMETHOD.soelim}
.  endif
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
.if !defined(TOOLS_IGNORE.awk) && !empty(_USE_TOOLS:Mawk)
.  if !empty(PKGPATH:Mlang/nawk)
MAKEFLAGS+=			TOOLS_IGNORE.awk=
.  elif !empty(_TOOLS_USE_PKGSRC.awk:M[yY][eE][sS])
TOOLS_DEPENDS.awk?=		nawk>=20040207:../../lang/nawk
TOOLS_CREATE+=			awk
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.awk=nawk
TOOLS_PATH.awk=			${TOOLS_PREFIX.awk}/bin/nawk
.  endif
.endif

.if !defined(TOOLS_IGNORE.bash) && !empty(_USE_TOOLS:Mbash)
.  if !empty(PKGPATH:Mshells/bash)
MAKEFLAGS+=			TOOLS_IGNORE.bash=
.  elif !empty(_TOOLS_USE_PKGSRC.bash:M[yY][eE][sS])
TOOLS_DEPENDS.bash?=		bash-[0-9]*:../../shells/bash
TOOLS_CREATE+=			bash
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bash=bash
TOOLS_PATH.bash=		${TOOLS_PREFIX.bash}/bin/bash
.  endif
.endif

.if !defined(TOOLS_IGNORE.bison) && !empty(_USE_TOOLS:Mbison)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison=
.  elif !empty(_TOOLS_USE_PKGSRC.bison:M[yY][eE][sS])
TOOLS_DEPENDS.bison?=		bison>=1.0:../../devel/bison
TOOLS_CREATE+=			bison
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bison=bison
TOOLS_PATH.bison=		${TOOLS_PREFIX.bison}/bin/bison
.  endif
.endif

.if !defined(TOOLS_IGNORE.bison-yacc) && !empty(_USE_TOOLS:Mbison-yacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.bison-yacc=
.  elif !empty(_TOOLS_USE_PKGSRC.bison-yacc:M[yY][eE][sS])
TOOLS_DEPENDS.bison-yacc?=	bison>=1.0:../../devel/bison
TOOLS_CREATE+=			bison-yacc
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bison-yacc=bison
TOOLS_PATH.bison-yacc=		${TOOLS_PREFIX.bison-yacc}/bin/bison
TOOLS_ARGS.bison-yacc=		-y
.  endif
TOOLS_CMD.bison-yacc=		${TOOLS_DIR}/bin/yacc
#
# bison/yacc is typically a build tool whose path is not embedded in
# any scripts or config files.  In this case, pass the full command
# line (path and arguments) of the tool to the GNU configure script
# so that bison will be correctly invoked in yacc-compatilility mode.
#
TOOLS_VALUE_GNU.bison-yacc=	${TOOLS_CMDLINE.bison-yacc}
.endif

.if !defined(TOOLS_IGNORE.byacc) && !empty(_USE_TOOLS:Mbyacc)
.  if !empty(PKGPATH:Mdevel/byacc)
MAKEFLAGS+=			TOOLS_IGNORE.byacc=
.  elif !empty(_TOOLS_USE_PKGSRC.byacc:M[yY][eE][sS])
TOOLS_DEPENDS.byacc?=		byacc>=20040328:../../devel/byacc
TOOLS_CREATE+=			byacc
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.byacc=byacc
TOOLS_PATH.byacc=		${TOOLS_PREFIX.byacc}/bin/yacc
TOOLS_CMD.byacc=		${TOOLS_DIR}/bin/yacc
.  endif
.endif

.if !defined(TOOLS_IGNORE.bzcat) && !empty(_USE_TOOLS:Mbzcat)
.  if !empty(PKGPATH:Marchivers/bzip2)
MAKEFLAGS+=			TOOLS_IGNORE.bzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.bzcat:M[yY][eE][sS])
TOOLS_DEPENDS.bzcat?=		bzip2>=0.9.0b:../../archivers/bzip2
TOOLS_CREATE+=			bzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bzcat=bzip2
TOOLS_PATH.bzcat=		${TOOLS_PREFIX.bzcat}/bin/bzcat
.  endif
.endif

.if !defined(TOOLS_IGNORE.csh) && !empty(_USE_TOOLS:Mcsh)
.  if !empty(PKGPATH:Mshells/tcsh)
MAKEFLAGS+=			TOOLS_IGNORE.csh=
.  elif !empty(_TOOLS_USE_PKGSRC.csh:M[yY][eE][sS])
TOOLS_DEPENDS.csh?=		tcsh-[0-9]*:../../shells/tcsh
TOOLS_CREATE+=			csh
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.csh=tcsh
TOOLS_PATH.csh=			${TOOLS_PREFIX.csh}/bin/tcsh
.  endif
.endif

.if !defined(TOOLS_IGNORE.file) && !empty(_USE_TOOLS:Mfile)
.  if !empty(PKGPATH:Msysutils/file)
MAKEFLAGS+=			TOOLS_IGNORE.file=
.  elif !empty(_TOOLS_USE_PKGSRC.file:M[yY][eE][sS])
TOOLS_DEPENDS.file?=		file>=4.13:../../sysutils/file
TOOLS_CREATE+=			file
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.file=file
TOOLS_PATH.file=		${TOOLS_PREFIX.file}/bin/file
.  endif
.endif

.if !defined(TOOLS_IGNORE.find) && !empty(_USE_TOOLS:Mfind)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.find=
.  elif !empty(_TOOLS_USE_PKGSRC.find:M[yY][eE][sS])
TOOLS_DEPENDS.find?=		findutils>=4.1:../../sysutils/findutils
TOOLS_CREATE+=			find
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.find=findutils
TOOLS_PATH.find=		${TOOLS_PREFIX.find}/bin/${GNU_PROGRAM_PREFIX}find
.  endif
.endif

.if !defined(TOOLS_IGNORE.flex) && !empty(_USE_TOOLS:Mflex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.flex=
.  elif !empty(_TOOLS_USE_PKGSRC.flex:M[yY][eE][sS])
.    include "../../devel/flex/buildlink3.mk"
_TOOLS_DEPENDS.flex=		# empty
.      for _dep_ in ${BUILDLINK_DEPENDS.flex}
_TOOLS_DEPENDS.flex+=		${_dep_}:${BUILDLINK_PKGSRCDIR.flex}
.      endfor
TOOLS_DEPENDS.flex?=		${_TOOLS_DEPENDS.flex}
TOOLS_CREATE+=			flex
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.flex=flex
TOOLS_PATH.flex=		${TOOLS_PREFIX.flex}/bin/flex
.  endif
TOOLS_ALIASES.flex=		lex
.endif

.if !defined(TOOLS_IGNORE.gawk) && !empty(_USE_TOOLS:Mgawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.gawk=
.  elif !empty(_TOOLS_USE_PKGSRC.gawk:M[yY][eE][sS])
TOOLS_DEPENDS.gawk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_CREATE+=			gawk
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gawk=gawk
TOOLS_PATH.gawk=		${TOOLS_PREFIX.gawk}/bin/${GNU_PROGRAM_PREFIX}awk
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
TOOLS_PATH.gm4=			${TOOLS_PREFIX.gm4}/bin/gm4
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
TOOLS_PATH.gmake=		${TOOLS_PREFIX.gmake}/bin/gmake
.  endif
.endif

.if !defined(TOOLS_IGNORE.gsed) && !empty(_USE_TOOLS:Mgsed)
.  if !empty(PKGPATH:Mtextproc/gsed)
MAKEFLAGS+=			TOOLS_IGNORE.gsed=
.  elif !empty(_TOOLS_USE_PKGSRC.gsed:M[yY][eE][sS])
TOOLS_DEPENDS.gsed?=		gsed>=3.0.2:../../textproc/gsed
TOOLS_CREATE+=			gsed
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gsed=gsed
TOOLS_PATH.gsed=		${TOOLS_PREFIX.gsed}/bin/${GNU_PROGRAM_PREFIX}sed
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
TOOLS_PATH.gtar=		${TOOLS_PREFIX.gtar}/bin/${GNU_PROGRAM_PREFIX}tar
.  endif
.endif

.if !defined(TOOLS_IGNORE.gunzip) && !empty(_USE_TOOLS:Mgunzip)
.  if !empty(PKGPATH:Marchivers/gzip-base)
MAKEFLAGS+=			TOOLS_IGNORE.gunzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gunzip:M[yY][eE][sS])
TOOLS_DEPENDS.gunzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gunzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gunzip=gzip-base
TOOLS_PATH.gunzip=		${TOOLS_PREFIX.gunzip}/bin/gunzip
TOOLS_ARGS.gunzip=		-f
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzcat) && !empty(_USE_TOOLS:Mgzcat)
.  if !empty(PKGPATH:Marchivers/gzip-base)
MAKEFLAGS+=			TOOLS_IGNORE.gzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.gzcat:M[yY][eE][sS])
TOOLS_DEPENDS.gzcat?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzcat=gzip-base
TOOLS_PATH.gzcat=		${TOOLS_PREFIX.gzcat}/bin/zcat
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzip) && !empty(_USE_TOOLS:Mgzip)
.  if !empty(PKGPATH:Marchivers/gzip-base)
MAKEFLAGS+=			TOOLS_IGNORE.gzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gzip:M[yY][eE][sS])
TOOLS_DEPENDS.gzip?=		gzip-base>=1.2.4b:../../archivers/gzip-base
TOOLS_CREATE+=			gzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzip=gzip-base
TOOLS_PATH.gzip=		${TOOLS_PREFIX.gzip}/bin/gzip
TOOLS_ARGS.gzip=		-nf ${GZIP}
.  endif
.endif

.if !defined(TOOLS_IGNORE.ksh) && !empty(_USE_TOOLS:Mksh)
.  if !empty(PKGPATH:Mshells/pdksh)
MAKEFLAGS+=			TOOLS_IGNORE.ksh=
.  elif !empty(_TOOLS_USE_PKGSRC.ksh:M[yY][eE][sS])
TOOLS_DEPENDS.ksh?=		pdksh>=5.2.14:../../shells/pdksh
TOOLS_CREATE+=			ksh
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ksh=pdksh
TOOLS_PATH.ksh=			${TOOLS_PREFIX.ksh}/bin/pdksh
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
TOOLS_DEPENDS.lex?=		${_TOOLS_DEPENDS.lex}
TOOLS_CREATE+=			lex
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lex=flex
TOOLS_PATH.lex=			${TOOLS_PREFIX.lex}/bin/flex
.  endif
.endif

.if !defined(TOOLS_IGNORE.lha) && !empty(_USE_TOOLS:Mlha)
.  if !empty(PKGPATH:Marchivers/lha)
MAKEFLAGS+=			TOOLS_IGNORE.lha=
.  elif !empty(_TOOLS_USE_PKGSRC.lha:M[yY][eE][sS])
TOOLS_DEPENDS.lha?=		lha>=114.9:../../archivers/lha
TOOLS_CREATE+=			lha
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lha=lha
TOOLS_PATH.lha=			${TOOLS_PREFIX.lha}/bin/lha
.  endif
.endif

.if !defined(TOOLS_IGNORE.m4) && !empty(_USE_TOOLS:Mm4)
.  if !empty(PKGPATH:Mdevel/m4)
MAKEFLAGS+=			TOOLS_IGNORE.m4=
.  elif !empty(_TOOLS_USE_PKGSRC.m4:M[yY][eE][sS])
TOOLS_DEPENDS.m4?=		m4>=1.4:../../devel/m4
TOOLS_CREATE+=			m4
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.m4=m4
TOOLS_PATH.m4=			${TOOLS_PREFIX.m4}/bin/gm4
.  endif
.endif

.if !defined(TOOLS_IGNORE.mail) && !empty(_USE_TOOLS:Mmail)
.  if !empty(PKGPATH:Mmail/nail)
MAKEFLAGS+=			TOOLS_IGNORE.mail=
.  elif !empty(_TOOLS_USE_PKGSRC.mail:M[yY][eE][sS])
TOOLS_DEPENDS.mail?=		nail>=11.22:../../mail/nail
TOOLS_CREATE+=			mail
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mail=nail
TOOLS_PATH.mail=		${TOOLS_PREFIX.mail}/bin/nail
.  endif
.endif

.if !defined(TOOLS_IGNORE.mktemp) && !empty(_USE_TOOLS:Mmktemp)
.  if !empty(PKGPATH:Msysutils/mktemp)
MAKEFLAGS+=			TOOLS_IGNORE.mktemp=
.  elif !empty(_TOOLS_USE_PKGSRC.mktemp:M[yY][eE][sS])
TOOLS_DEPENDS.mktemp?=		mktemp>=1.5:../../sysutils/mktemp
TOOLS_CREATE+=			mktemp
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mktemp=mktemp
TOOLS_PATH.mktemp=		${TOOLS_PREFIX.mktemp}/bin/mktemp
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
TOOLS_PATH.mtree=		${TOOLS_PREFIX.mtree}/bin/mtree
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(_USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  elif !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
TOOLS_DEPENDS.patch?=		patch>=2.2:../../devel/patch
TOOLS_CREATE+=			patch
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.patch=patch
TOOLS_PATH.patch=		${TOOLS_PREFIX.patch}/bin/gpatch
_PATCH_CAN_BACKUP=		yes
_PATCH_BACKUP_ARG?=		-b -V simple -z
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
TOOLS_PATH.pax=			${TOOLS_PREFIX.pax}/bin/pax
.  endif
.endif

.if !defined(TOOLS_IGNORE.perl) && !empty(_USE_TOOLS:Mperl)
.  if !empty(PKGPATH:Mlang/perl5)
MAKEFLAGS+=			TOOLS_IGNORE.perl=
.  elif !empty(_TOOLS_USE_PKGSRC.perl:M[yY][eE][sS])
.    include "../../lang/perl5/version.mk"
TOOLS_DEPENDS.perl?=		perl>=${PERL5_REQD}:../../lang/perl5
TOOLS_CREATE+=			perl
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.perl=perl
TOOLS_PATH.perl=		${TOOLS_PREFIX.perl}/bin/perl
.  endif
.endif

.if !defined(TOOLS_IGNORE.pkg-config) && !empty(_USE_TOOLS:Mpkg-config)
.  if !empty(PKGPATH:Mdevel/pkg-config)
MAKEFLAGS+=			TOOLS_IGNORE.pkg-config=
.  elif !empty(_TOOLS_USE_PKGSRC.pkg-config:M[yY][eE][sS])
TOOLS_DEPENDS.pkg-config?=	pkg-config>=0.19:../../devel/pkg-config
TOOLS_CREATE+=			pkg-config
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pkg-config=pkg-config
TOOLS_PATH.pkg-config=		${TOOLS_PREFIX.pkg-config}/bin/pkg-config
.  endif
.endif

.if !defined(TOOLS_IGNORE.pod2man) && !empty(_USE_TOOLS:Mpod2man)
.  if !empty(PKGPATH:Mlang/perl5)
MAKEFLAGS+=			TOOLS_IGNORE.pod2man=
.  elif !empty(_TOOLS_USE_PKGSRC.pod2man:M[yY][eE][sS])
.    include "../../lang/perl5/version.mk"
TOOLS_DEPENDS.pod2man?=		perl>=${PERL5_REQD}:../../lang/perl5
TOOLS_CREATE+=			pod2man
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pod2man=perl
TOOLS_PATH.pod2man=		${TOOLS_PREFIX.pod2man}/bin/pod2man
.  endif
.endif

.if !defined(TOOLS_IGNORE.sed) && !empty(_USE_TOOLS:Msed)
.  if !empty(PKGPATH:Mtextproc/nbsed)
MAKEFLAGS+=			TOOLS_IGNORE.sed=
.  elif !empty(_TOOLS_USE_PKGSRC.sed:M[yY][eE][sS])
TOOLS_DEPENDS.sed?=		nbsed>=20040821:../../textproc/nbsed
TOOLS_CREATE+=			sed
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.sed=nbsed
TOOLS_PATH.sed=			${TOOLS_PREFIX.nbsed}/bin/nbsed
.  endif
.endif

.if !defined(TOOLS_IGNORE.sh) && !empty(_USE_TOOLS:Msh)
.  if !empty(PKGPATH:Mshells/pdksh)
MAKEFLAGS+=			TOOLS_IGNORE.sh=
.  elif !empty(_TOOLS_USE_PKGSRC.sh:M[yY][eE][sS])
TOOLS_DEPENDS.sh?=		pdksh>=5.2.14:../../shells/pdksh
TOOLS_CREATE+=			sh
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.sh=pdksh
TOOLS_PATH.sh=			${TOOLS_PREFIX.sh}/bin/pdksh
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
TOOLS_PATH.shlock=		${TOOLS_PREFIX.shlock}/bin/shlock
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
TOOLS_PATH.tar=			${TOOLS_PREFIX.tar}/bin/tar
.  endif
.endif

.if !defined(TOOLS_IGNORE.tclsh) && !empty(_USE_TOOLS:Mtclsh)
.  if !empty(PKGPATH:Mlang/tcl)
MAKEFLAGS+=			TOOLS_IGNORE.tclsh=
.  elif !empty(_TOOLS_USE_PKGSRC.tclsh:M[yY][eE][sS])
TOOLS_DEPENDS.tclsh?=		tcl>=8.4:../../lang/tcl
TOOLS_CREATE+=			tclsh
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tclsh=tcl
TOOLS_PATH.tclsh=		${TOOLS_PREFIX.tclsh}/bin/tclsh
.  endif
.endif

.if !defined(TOOLS_IGNORE.ttmkfdir) && !empty(_USE_TOOLS:Mttmkfdir)
.  if !empty(PKGPATH:Mfonts/ttmkfdir2)
MAKEFLAGS+=			TOOLS_IGNORE.ttmkfdir=
.  elif !empty(_TOOLS_USE_PKGSRC.ttmkfdir:M[yY][eE][sS])
TOOLS_DEPENDS.ttmkfdir?=	ttmkfdir2>=20021109:../../fonts/ttmkfdir2
TOOLS_CREATE+=			ttmkfdir
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ttmkfdir=ttmkfdir2
TOOLS_PATH.ttmkfdir=		${TOOLS_PREFIX.ttmkfdir}/bin/ttmkfdir
.  endif
.endif

.if !defined(TOOLS_IGNORE.type1inst) && !empty(_USE_TOOLS:Mtype1inst)
.  if !empty(PKGPATH:Mfonts/type1inst)
MAKEFLAGS+=			TOOLS_IGNORE.type1inst=
.  elif !empty(_TOOLS_USE_PKGSRC.type1inst:M[yY][eE][sS])
TOOLS_DEPENDS.type1inst?=	type1inst2>=0.6.1:../../fonts/type1inst
TOOLS_CREATE+=			type1inst
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.type1inst=type1inst
TOOLS_PATH.type1inst=		${TOOLS_PREFIX.type1inst}/bin/type1inst
.  endif
.endif

.if !defined(TOOLS_IGNORE.unrar) && !empty(_USE_TOOLS:Munrar)
.  if !empty(PKGPATH:Marchivers/unrar)
MAKEFLAGS+=			TOOLS_IGNORE.unrar=
.  elif !empty(_TOOLS_USE_PKGSRC.unrar:M[yY][eE][sS])
TOOLS_DEPENDS.unrar?=		unrar>=3.3.4:../../archivers/unrar
TOOLS_CREATE+=			unrar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unrar=unrar
TOOLS_PATH.unrar=		${TOOLS_PREFIX.unrar}/bin/unrar
.  endif
.endif

.if !defined(TOOLS_IGNORE.unzip) && !empty(_USE_TOOLS:Munzip)
.  if !empty(PKGPATH:Marchivers/unzip)
MAKEFLAGS+=			TOOLS_IGNORE.unzip=
.  elif !empty(_TOOLS_USE_PKGSRC.unzip:M[yY][eE][sS])
TOOLS_DEPENDS.unzip?=		unzip-[0-9]*:../../archivers/unzip
TOOLS_CREATE+=			unzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unzip=unzip
TOOLS_PATH.unzip=		${TOOLS_PREFIX.unzip}/bin/unzip
.  endif
.endif

.if !defined(TOOLS_IGNORE.unzoo) && !empty(_USE_TOOLS:Munzoo)
.  if !empty(PKGPATH:Marchivers/unzoo)
MAKEFLAGS+=			TOOLS_IGNORE.unzoo=
.  elif !empty(_TOOLS_USE_PKGSRC.unzoo:M[yY][eE][sS])
TOOLS_DEPENDS.unzoo?=		unzoo-[0-9]*:../../archivers/unzoo
TOOLS_CREATE+=			unzoo
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.unzoo=unzoo
TOOLS_PATH.unzoo=		${TOOLS_PREFIX.unzoo}/bin/unzoo
.  endif
.endif

.if !defined(TOOLS_IGNORE.wish) && !empty(_USE_TOOLS:Mwish)
.  if !empty(PKGPATH:Mx11/tk)
MAKEFLAGS+=			TOOLS_IGNORE.wish=
.  elif !empty(_TOOLS_USE_PKGSRC.wish:M[yY][eE][sS])
TOOLS_DEPENDS.wish?=		tk>=8.4:../../x11/tk
TOOLS_CREATE+=			wish
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.wish=tk
TOOLS_PATH.wish=		${TOOLS_PREFIX.wish}/bin/wish
.  endif
.endif

.if !defined(TOOLS_IGNORE.xargs) && !empty(_USE_TOOLS:Mxargs)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=			TOOLS_IGNORE.xargs=
.  elif !empty(_TOOLS_USE_PKGSRC.xargs:M[yY][eE][sS])
TOOLS_DEPENDS.xargs?=		findutils>=4.1:../../sysutils/findutils
TOOLS_CREATE+=			xargs
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.xargs=findutils
TOOLS_PATH.xargs=		${TOOLS_PREFIX.xargs}/bin/${GNU_PROGRAM_PREFIX}xargs
TOOLS_ARGS.xargs=		-r	# don't run command if stdin is empty
.  endif
.endif

.if !defined(TOOLS_IGNORE.yacc) && !empty(_USE_TOOLS:Myacc)
.  if !empty(PKGPATH:Mdevel/bison)
MAKEFLAGS+=			TOOLS_IGNORE.yacc=
.  elif !empty(_TOOLS_USE_PKGSRC.yacc:M[yY][eE][sS])
TOOLS_DEPENDS.yacc?=		bison>=1.0:../../devel/bison
TOOLS_CREATE+=			yacc
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.yacc=bison
TOOLS_PATH.yacc=		${TOOLS_PREFIX.yacc}/bin/bison
TOOLS_ARGS.yacc=		-y
#
# bison/yacc is typically a build tool whose path is not embedded in
# any scripts or config files.  In this case, pass the full command
# line (path and arguments) of the tool to the GNU configure script
# so that bison will be correctly invoked in yacc-compatilility mode.
#
TOOLS_VALUE_GNU.yacc=		${TOOLS_CMDLINE.yacc}
.  endif
.endif

######################################################################

# These tools are all supplied by the sysutuils/coreutils package if
# there is no native tool available.
#
_TOOLS.coreutils=	basename cat chgrp chmod chown cp cut date	\
			dirname echo env expr false head hostname id	\
			install ln ls mkdir mv nice printf pwd rm rmdir	\
			sleep sort tail tee test touch tr true tsort wc

.for _t_ in ${_TOOLS.coreutils}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=coreutils
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.    endif
.  endif
.endfor

# The ``['' tool is special because it matches a token that's interpreted
# by bmake.
#
.if !defined(TOOLS_IGNORE.[) && !empty(_USE_TOOLS:M\[)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=		TOOLS_IGNORE.[=
.  elif !empty(_TOOLS_USE_PKGSRC.[:M[yY][eE][sS])
TOOLS_DEPENDS.[?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=		[
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.[=coreutils
TOOLS_PATH.[=		${TOOLS_PREFIX.[}/bin/${GNU_PROGRAM_PREFIX}[
.  endif
.endif

######################################################################

# These tools are all supplied by the textproc/grep package if there is
# no native tool available.
#
_TOOLS.grep=	egrep fgrep grep

.for _t_ in ${_TOOLS.grep}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mtextproc/grep)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	grep>=2.5.1:../../textproc/grep
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=grep
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by the textproc/groff package if there is
# no native tool available.
#
_TOOLS.groff=	nroff soelim tbl

.for _t_ in ${_TOOLS.groff}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	groff>=1.19nb4:../../textproc/groff
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=groff
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

# The ``gsoelim'' tool is special because there's actually no tool named
# ``gsoelim'' -- the real tool is called just ``soelim''.
#
.if !defined(TOOLS_IGNORE.gsoelim) && !empty(_USE_TOOLS:Mgsoelim)
.  if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=		TOOLS_IGNORE.gsoelim=
.  elif !empty(_TOOLS_USE_PKGSRC.gsoelim:M[yY][eE][sS])
TOOLS_DEPENDS.gsoelim?=	groff>=1.19nb4:../../textproc/groff
TOOLS_CREATE+=		gsoelim
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.gsoelim=groff
TOOLS_PATH.gsoelim=	${TOOLS_PREFIX.gsoelim}/bin/soelim
.  endif
TOOLS_ALIASES.gsoelim=	soelim
.endif

######################################################################

# These tools are all supplied by the devel/diffutils package if there is
# no native tool available.
#
_TOOLS.diffutils=	cmp diff

.for _t_ in ${_TOOLS.diffutils}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mdevel/diffutils)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	diffutils>=2.8.1:../../devel/diffutils
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=diffutils
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by a Ghostscript package if there is no
# native tool available.
#
_TOOLS.ghostscript=	gs pdf2ps ps2pdf

# This is the minimum version of Ghostscript required by the current
# package.
#
GHOSTSCRIPT_REQD?=	6.01

# Set TOOLS_DEPENDS.ghostscript to an appropriate dependency based on
# various package options.
#
.if !defined(TOOLS_DEPENDS.ghostscript)
_TOOLS_DEP.ghostscript:=	ghostscript
_TOOLS_DEP.ghostscript:=	${_TOOLS_DEP.ghostscript},ghostscript-afpl
_TOOLS_DEP.ghostscript:=	${_TOOLS_DEP.ghostscript},ghostscript-esp
_TOOLS_DEP.ghostscript:=	${_TOOLS_DEP.ghostscript},ghostscript-gnu
#
# Determine the default Ghostscript package to build based on the
# PKG_OPTIONS for the current package.
#
.  if (defined(PKG_OPTIONS) && !empty(PKG_OPTIONS:Mcups))
_TOOLS_PKGSRCDIR.ghostscript=	../../print/ghostscript-esp
.  else
_TOOLS_PKGSRCDIR.ghostscript=	../../print/ghostscript-gnu
.  endif
TOOLS_DEPENDS.ghostscript=	{${_TOOLS_DEP.ghostscript}}>=${GHOSTSCRIPT_REQD}:${_TOOLS_PKGSRCDIR.ghostscript}
MAKEVARS+=			${TOOLS_DEPENDS.ghostscript}
.endif

.for _t_ in ${_TOOLS.ghostscript}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mprint/ghostscript) || \
        !empty(PKGPATH:Mprint/ghostscript-afpl) || \
        !empty(PKGPATH:Mprint/ghostscript-esp) || \
        !empty(PKGPATH:Mprint/ghostscript-gnu)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	${TOOLS_DEPENDS.ghostscript}
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=${TOOLS_DEPENDS.ghostscript:C/:.*//}
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by an X11 clients package if there is no
# native tool available.
#
_TOOLS.x11-clients=	bdftopcf iceauth mkfontdir mkfontscale \
			makepsres xmessage

.for _t_ in ${_TOOLS.x11-clients}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mx11/XFree86-clients) || \
        !empty(PKGPATH:Mx11/xorg-clients)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_CREATE+=		${_t_}
.      if defined(X11_TYPE) && !empty(X11_TYPE:MXFree86)
TOOLS_DEPENDS.${_t_}?=	XFree86-clients>=4.4.0:../../x11/XFree86-clients
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=XFree86-clients
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/${X11ROOT_PREFIX}/bin/${_t_}
.      elif defined(X11_TYPE) && !empty(X11_TYPE:Mxorg)
TOOLS_DEPENDS.${_t_}?=	xorg-clients>=6.8:../../x11/xorg-clients
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=xorg-clients
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/${X11ROOT_PREFIX}/bin/${_t_}
.      else # !empty(X11_TYPE:Mnative)
TOOLS_PATH.${_t_}=	${X11BASE}/bin/${_t_}
.      endif
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by an X11 imake package if there is no
# native tool available.
#
_TOOLS.x11-imake=	imake mkdirhier xmkmf

.for _t_ in ${_TOOLS.x11-imake}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mx11/XFree86-imake) || !empty(PKGPATH:Mx11/xorg-imake)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_CREATE+=		${_t_}
.      if defined(X11_TYPE) && !empty(X11_TYPE:MXFree86)
TOOLS_DEPENDS.${_t_}?=	XFree86-imake>=4.4.0:../../x11/XFree86-imake
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=imake
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/${X11ROOT_PREFIX}/bin/${_t_}
.      elif defined(X11_TYPE) && !empty(X11_TYPE:Mxorg)
TOOLS_DEPENDS.${_t_}?=	xorg-imake>=6.8:../../x11/xorg-imake
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=xorg-imake
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/${X11ROOT_PREFIX}/bin/${_t_}
.      else # !empty(X11_TYPE:Mnative)
TOOLS_PATH.${_t_}=	${X11BASE}/bin/${_t_}
.      endif
.    endif
.  endif
.endfor
#
# If IMAKE is defined, then use that as the path to the imake binary.
#
.if !defined(TOOLS_IGNORE.imake) && !empty(_USE_TOOLS:Mimake) && defined(IMAKE)
TOOLS_PATH.xmkmf=	${IMAKE}
.endif
#
# If we're using xpkgwedge, then we need to invoke the special xmkmf
# script that will find imake config files in both ${PREFIX} and in
# ${X11BASE}.
#
.if !defined(TOOLS_IGNORE.xmkmf) && !empty(_USE_TOOLS:Mxmkmf)
.  if !empty(USE_XPKGWEDGE:M[yY][eE][sS])
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.xpkgwedge=xpkgwedge
TOOLS_PATH.xmkmf=	${TOOLS_PREFIX.xpkgwedge}/bin/pkgxmkmf
.  endif
.endif

######################################################################

# Compute the locations of the pkgsrc-supplied tools.
FIND_PREFIX:=	${TOOLS_FIND_PREFIX}
.include "../../mk/find-prefix.mk"

######################################################################

.for _t_ in ${_USE_TOOLS}
.  if !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS]) && \
      !defined(TOOLS_IGNORE.${_t_})
#####
##### Add the dependencies for each pkgsrc-supplied tool.
#####
.      if defined(_TOOLS_DEPMETHOD.${_t_}) && defined(TOOLS_DEPENDS.${_t_})
.        for _dep_ in ${TOOLS_DEPENDS.${_t_}}
.          if empty(${_TOOLS_DEPMETHOD.${_t_}}:C/\:.*$//:M${_dep_:C/\:.*$//})
${_TOOLS_DEPMETHOD.${_t_}}+=	${_dep_}
.          endif
.        endfor
.      endif
.  elif defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
#####
##### For each system-supplied tool, break the tool down into a path
##### and arguments so that either a symlink or a wrapper will be
##### properly created.
#####
TOOLS_CREATE+=		${_t_}
TOOLS_PATH.${_t_}?=	\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_ARGS.${_t_}?=	\
	${TOOLS_PLATFORM.${_t_}:C/^/_asdf_/1:N_asdf_*}
.  endif
###
### For each tool, TOOLS_CMDLINE.<tool> is the full command (path and
### arguments) that should be run to properly execute the tool.
###
.  if defined(TOOLS_PATH.${_t_}) && !empty(TOOLS_PATH.${_t_})
.    if defined(TOOLS_ARGS.${_t_}) && !empty(TOOLS_ARGS.${_t_})
TOOLS_CMDLINE.${_t_}?=	${TOOLS_PATH.${_t_}} ${TOOLS_ARGS.${_t_}}
.    else
TOOLS_CMDLINE.${_t_}?=	${TOOLS_PATH.${_t_}}
.    endif
.  endif
###
### If a "TOOL" name is associated with the tool, then export two
### variables:
###
###   (1) The "TOOLS_TOOL" name for each tool points to the path
###       to the real command, e.g. TOOLS_TBL, TOOLS_YACC, etc.
###
###   (2) The "TOOLS_CMDLINE_TOOL" name for each tool to point to the
###       full command, e.g. TOOLS_CMDLINE_TBL, TOOLS_CMDLINE_YACC,
###       etc.
###
.  if defined(_TOOLS_VARNAME.${_t_})
.    if defined(TOOLS_PATH.${_t_})
TOOLS_${_TOOLS_VARNAME.${_t_}}=		${TOOLS_PATH.${_t_}}
.    endif
.    if defined(TOOLS_CMDLINE.${_t_})
TOOLS_CMDLINE_${_TOOLS_VARNAME.${_t_}}=	${TOOLS_CMDLINE.${_t_}}
.      for _v_ in ${_TOOLS_VARNAME.${_t_}}
${_v_}?=	${TOOLS_CMDLINE_${_TOOLS_VARNAME.${_t_}}}
.      endfor
.    endif
.  endif
.endfor

######################################################################

# For each tool that pkgsrc requires, make sure that the "TOOL" name
# points to the real command, e.g., AWK, SED, etc., provided that
# "TOOL" has been associated with <tool>.
#
.for _t_ in ${USE_TOOLS:M*\:pkgsrc:C/:.*//:O:u}
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

######################################################################

# For packages that use GNU configure scripts, pass the appropriate
# environment variables to ensure the proper command is invoked for
# each tool.  We do this since these paths may be hardcoded into
# package scripts, and if they're not pre-specified, then they'll be
# searched for in the PATH, which would find the ones in ${TOOLS_DIR}.
#
# The value passed via the shell environment is stored in
# TOOLS_VALUE_GNU.<tool>, which defaults to just the path to the
# tool.
#
.for _t_ in ${_USE_TOOLS}
.  if defined(GNU_CONFIGURE)
.    if defined(TOOLS_${_TOOLS_VARNAME.${_t_}})
TOOLS_VALUE_GNU.${_t_}?=	${TOOLS_PATH.${_t_}}
.    endif
.    if defined(TOOLS_VALUE_GNU.${_t_})
.      for _v_ in ${_TOOLS_VARNAME_GNU.${_t_}}
CONFIGURE_ENV+=		${_v_}=${TOOLS_VALUE_GNU.${_t_}:Q}
.      endfor
.    endif
.  endif
.endfor
