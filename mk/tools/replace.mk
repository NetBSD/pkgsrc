# $NetBSD: replace.mk,v 1.267 2014/02/14 07:43:46 obache Exp $
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
#    BOOTSTRAP_DEPENDS:	:bootstrap
#    TOOL_DEPENDS:	:build (default), :pkgsrc
#    DEPENDS:		:run
#
.for _t_ in ${USE_TOOLS:N*\:*} ${USE_TOOLS:M*\:bootstrap}
_TOOLS_DEPMETHOD.${_t_:C/:.*//}=	BOOTSTRAP_DEPENDS
.endfor
.for _t_ in ${USE_TOOLS:N*\:*} ${USE_TOOLS:M*\:build} ${USE_TOOLS:M*\:pkgsrc}
_TOOLS_DEPMETHOD.${_t_:C/:.*//}=	TOOL_DEPENDS
.endfor
.for _t_ in ${USE_TOOLS:M*\:run}
_TOOLS_DEPMETHOD.${_t_:C/:.*//}=	DEPENDS
.endfor

.if !empty(_USE_TOOLS:Mbison-yacc)	# bison-yacc > yacc
.  if defined(_TOOLS_DEPMETHOD.bison-yacc) && \
      (${_TOOLS_DEPMETHOD.bison-yacc} == "TOOL_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.yacc)
_TOOLS_DEPMETHOD.bison-yacc=	${_TOOLS_DEPMETHOD.yacc}
.  endif
.endif
.if !empty(_USE_TOOLS:Mflex)		# flex > lex
.  if (${_TOOLS_DEPMETHOD.flex} == "TOOL_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.lex)
_TOOLS_DEPMETHOD.flex=		${_TOOLS_DEPMETHOD.lex}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgawk)		# gawk > awk
.  if (${_TOOLS_DEPMETHOD.gawk} == "TOOL_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.awk)
_TOOLS_DEPMETHOD.gawk=		${_TOOLS_DEPMETHOD.awk}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgm4)		# gm4 > m4
.  if (${_TOOLS_DEPMETHOD.gm4} == "TOOL_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.m4)
_TOOLS_DEPMETHOD.gm4=		${_TOOLS_DEPMETHOD.m4}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgsed)		# gsed > sed
.  if (${_TOOLS_DEPMETHOD.gsed} == "TOOL_DEPENDS") && \
      defined(_TOOLS_DEPMETHOD.sed)
_TOOLS_DEPMETHOD.gsed=		${_TOOLS_DEPMETHOD.sed}
.  endif
.endif
.if !empty(_USE_TOOLS:Mgsoelim)		# gsoelim > soelim
.  if (${_TOOLS_DEPMETHOD.gsoelim} == "TOOL_DEPENDS") && \
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
.if !defined(TOOLS_IGNORE.7za) && !empty(_USE_TOOLS:M7za)
.  if !empty(PKGPATH:Marchivers/p7zip)
MAKEFLAGS+=			TOOLS_IGNORE.7za=
.  elif !empty(_TOOLS_USE_PKGSRC.7za:M[yY][eE][sS])
TOOLS_DEPENDS.7za?=		p7zip>=9.04:../../archivers/p7zip
TOOLS_CREATE+=			7za
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.7za=7za
TOOLS_PATH.7za=			${TOOLS_PREFIX.7za}/bin/7za
.  endif
.endif

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

.if !defined(TOOLS_IGNORE.bsdtar) && !empty(_USE_TOOLS:Mbsdtar)
.  if !empty(PKGPATH:Marchivers/bsdtar)
MAKEFLAGS+=			TOOLS_IGNORE.bsdtar=
.  elif !empty(_TOOLS_USE_PKGSRC.bsdtar:M[yY][eE][sS])
TOOLS_DEPENDS.bsdtar?=		bsdtar-[0-9]*:../../archivers/bsdtar
TOOLS_CREATE+=			bsdtar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bsdtar=bsdtar
TOOLS_PATH.bsdtar=		${TOOLS_PREFIX.bsdtar}/bin/bsdtar
.  endif
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

_TOOLS.bzip2=	bzip2 bzcat
.for _t_ in ${_TOOLS.bzip2}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Marchivers/bzip2)
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=		bzip2>=0.9.0b:../../archivers/bzip2
TOOLS_CREATE+=			${_t_}
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.${_t_}=bzip2
TOOLS_PATH.${_t_}=		${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

.if !defined(TOOLS_IGNORE.chrpath) && !empty(_USE_TOOLS:Mchrpath)
.  if !empty(PKGPATH:Mdevel/chrpath)
MAKEFLAGS+=			TOOLS_IGNORE.chrpath=
.  elif !empty(_TOOLS_USE_PKGSRC.chrpath:M[yY][eE][sS])
TOOLS_DEPENDS.chrpath?=		chrpath>=0.13:../../devel/chrpath
TOOLS_CREATE+=			chrpath
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.chrpath=chrpath
TOOLS_PATH.chrpath=		${TOOLS_PREFIX.chrpath}/bin/chrpath
.  endif
.endif

_TOOLS.cmake=	cmake cpack
.for _t_ in ${_TOOLS.cmake}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mdevel/cmake)
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=		cmake>=2.8.1nb1:../../devel/cmake
TOOLS_CREATE+=			${_t_}
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.${_t_}=cmake
TOOLS_PATH.${_t_}=		${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

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

.if !defined(TOOLS_IGNORE.curl) && !empty(_USE_TOOLS:Mcurl)
.  if !empty(PKGPATH:Mwww/curl)
MAKEFLAGS+=			TOOLS_IGNORE.curl=
.  elif !empty(_TOOLS_USE_PKGSRC.curl:M[yY][eE][sS])
TOOLS_DEPENDS.curl?=		curl-[0-9]*:../../www/curl
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.curl=curl
TOOLS_PATH.curl=		${TOOLS_PREFIX.curl}/bin/curl
.  endif
.endif

.if !defined(TOOLS_IGNORE.fetch) && !empty(_USE_TOOLS:Mfetch)
.  if !empty(PKGPATH:Mnet/fetch)
MAKEFLAGS+=			TOOLS_IGNORE.fetch=
.  elif !empty(_TOOLS_USE_PKGSRC.fetch:M[yY][eE][sS])
TOOLS_DEPENDS.fetch?=		fetch-[0-9]*:../../net/fetch
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.fetch=fetch
TOOLS_PATH.fetch=		${TOOLS_PREFIX.fetch}/bin/fetch
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
TOOLS_PATH.find=		${TOOLS_PREFIX.find}/bin/gfind
.  endif
.endif

.if !defined(TOOLS_IGNORE.flex) && !empty(_USE_TOOLS:Mflex)
.  if !empty(PKGPATH:Mdevel/flex)
MAKEFLAGS+=			TOOLS_IGNORE.flex=
.  elif !empty(_TOOLS_USE_PKGSRC.flex:M[yY][eE][sS])
.    include "../../devel/flex/buildlink3.mk"
_TOOLS_DEPENDS.flex=		# empty
.    for _dep_ in ${BUILDLINK_API_DEPENDS.flex}
_TOOLS_DEPENDS.flex+=		${_dep_}:${BUILDLINK_PKGSRCDIR.flex}
.    endfor
TOOLS_DEPENDS.flex?=		${_TOOLS_DEPENDS.flex}
TOOLS_CREATE+=			flex
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.flex=flex
TOOLS_PATH.flex=		${TOOLS_PREFIX.flex}/bin/flex
.  endif
TOOLS_ALIASES.flex=		lex
.endif

.if !defined(TOOLS_IGNORE.ftp) && !empty(_USE_TOOLS:Mftp)
.  if !empty(PKGPATH:Mnet/tnftp)
MAKEFLAGS+=			TOOLS_IGNORE.ftp=
.  elif !empty(_TOOLS_USE_PKGSRC.ftp:M[yY][eE][sS])
TOOLS_DEPENDS.ftp?=		tnftp-[0-9]*:../../net/tnftp
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ftp=ftp
TOOLS_PATH.ftp=			${TOOLS_PREFIX.ftp}/bin/ftp
.  endif
.endif

.if !defined(TOOLS_IGNORE.gawk) && !empty(_USE_TOOLS:Mgawk)
.  if !empty(PKGPATH:Mlang/gawk)
MAKEFLAGS+=			TOOLS_IGNORE.gawk=
.  elif !empty(_TOOLS_USE_PKGSRC.gawk:M[yY][eE][sS])
TOOLS_DEPENDS.gawk?=		gawk>=3.1.1:../../lang/gawk
TOOLS_CREATE+=			gawk
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gawk=gawk
TOOLS_PATH.gawk=		${TOOLS_PREFIX.gawk}/bin/gawk
.  endif
TOOLS_ALIASES.gawk=		awk
.endif

.if !defined(TOOLS_IGNORE.gem) && !empty(_USE_TOOLS:Mgem)
.  if !empty(PKGPATH:Mmisc/rubygems)
MAKEFLAGS+=			TOOLS_IGNORE.gem=
.  elif !empty(_TOOLS_USE_PKGSRC.gem:M[yY][eE][sS])
.    if !defined(RUBY_VER) || !empty(RUBY_VER:M18)
TOOLS_DEPENDS.gem?=		${RUBY_PKGPREFIX}-rubygems-[0-9]*:../../misc/rubygems
.    else
TOOLS_DEPENDS.gem?=		${RUBY_BASE}>=${RUBY_VERSION}:../../lang/${RUBY_BASE}
.    endif
TOOLS_CREATE+=			gem
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gem=gem
TOOLS_PATH.gem=			${TOOLS_PREFIX.gem}/bin/gem${RUBY_VER}
.  endif
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
TOOLS_DEPENDS.gmake?=		gmake>=${GMAKE_REQD}:../../devel/gmake
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
TOOLS_PATH.gsed=		${TOOLS_PREFIX.gsed}/bin/gsed
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
TOOLS_PATH.gtar=		${TOOLS_PREFIX.gtar}/bin/gtar
.  endif
.endif

.if !defined(TOOLS_IGNORE.gunzip) && !empty(_USE_TOOLS:Mgunzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gunzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gunzip:M[yY][eE][sS])
TOOLS_DEPENDS.gunzip?=		{gzip>=1.2.4b,gzip-base>=1.2.4b}:../../archivers/gzip
TOOLS_CREATE+=			gunzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gunzip=gzip
TOOLS_PATH.gunzip=		${TOOLS_PREFIX.gunzip}/bin/gunzip
TOOLS_ARGS.gunzip=		-f
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzcat) && !empty(_USE_TOOLS:Mgzcat)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.gzcat:M[yY][eE][sS])
TOOLS_DEPENDS.gzcat?=		{gzip>=1.2.4b,gzip-base>=1.2.4b}:../../archivers/gzip
TOOLS_CREATE+=			gzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzcat=gzip
TOOLS_PATH.gzcat=		${TOOLS_PREFIX.gzcat}/bin/zcat
.  endif
.endif

.if !defined(TOOLS_IGNORE.gzip) && !empty(_USE_TOOLS:Mgzip)
.  if !empty(PKGPATH:Marchivers/gzip)
MAKEFLAGS+=			TOOLS_IGNORE.gzip=
.  elif !empty(_TOOLS_USE_PKGSRC.gzip:M[yY][eE][sS])
TOOLS_DEPENDS.gzip?=		{gzip>=1.2.4b,gzip-base>=1.2.4b}:../../archivers/gzip
TOOLS_CREATE+=			gzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.gzip=gzip
TOOLS_PATH.gzip=		${TOOLS_PREFIX.gzip}/bin/gzip
TOOLS_ARGS.gzip=		-nf ${GZIP}
.  endif
.endif

.if !defined(TOOLS_IGNORE.ident) && !empty(_USE_TOOLS:Mident)
.  if !empty(PKGPATH:Mdevel/rcs)
MAKEFLAGS+=			TOOLS_IGNORE.ident=
.  elif !empty(_TOOLS_USE_PKGSRC.ident:M[yY][eE][sS])
TOOLS_DEPENDS.ident?=		rcs-[0-9]*:../../devel/rcs
TOOLS_CREATE+=			ident
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ident=rcs
TOOLS_PATH.ident=		${TOOLS_PREFIX.ident}/bin/ident
.  endif
.endif

.if !defined(TOOLS_IGNORE.install-info) && !empty(_USE_TOOLS:Minstall-info)
.  if !empty(PKGPATH:Mpkgtools/pkg_install-info)
MAKEFLAGS+=			TOOLS_IGNORE.install-info=
.  elif !empty(_TOOLS_USE_PKGSRC.install-info:M[yY][eE][sS])
TOOLS_DEPENDS.install-info?=	pkg_install-info-[0-9]*:../../pkgtools/pkg_install-info
TOOLS_CREATE+=			install-info
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.install-info=pkg_install-info
TOOLS_PATH.install-info=	${TOOLS_PREFIX.install-info}/bin/pkg_install-info
.  endif
.endif
#
# Always create an install-info tool that is a "no operation" command, as
# registration of info files is handled by the INSTALL script.
#
TOOLS_SCRIPT.install-info=	exit 0

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
.    for _dep_ in ${BUILDLINK_API_DEPENDS.flex}
_TOOLS_DEPENDS.lex+=		${_dep_}:${BUILDLINK_PKGSRCDIR.flex}
.    endfor
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

.if !defined(TOOLS_IGNORE.lzip) && !empty(_USE_TOOLS:Mlzip)
.  if !empty(PKGPATH:Marchivers/lzip)
MAKEFLAGS+=			TOOLS_IGNORE.lzip=
.  elif !empty(_TOOLS_USE_PKGSRC.lzip:M[yY][eE][sS])
TOOLS_DEPENDS.lzip?=		lzip>=1.14:../../archivers/lzip
TOOLS_CREATE+=			lzip
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lzip=lzip
TOOLS_PATH.lzip=		${TOOLS_PREFIX.lzip}/bin/lzip
.  endif
.endif

.if !defined(TOOLS_IGNORE.lzcat) && !empty(_USE_TOOLS:Mlzcat)
.  if !empty(PKGPATH:Marchivers/xz)
MAKEFLAGS+=			TOOLS_IGNORE.lzcat=
.  elif !empty(_TOOLS_USE_PKGSRC.lzcat:M[yY][eE][sS])
TOOLS_DEPENDS.lzcat?=		xz>=4.999.9betanb1:../../archivers/xz
TOOLS_CREATE+=			lzcat
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.lzcat=lzcat
TOOLS_PATH.lzcat=		${TOOLS_PREFIX.lzcat}/bin/lzcat
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
.  if !empty(PKGPATH:Mmail/heirloom-mailx)
MAKEFLAGS+=			TOOLS_IGNORE.mail=
.  elif !empty(_TOOLS_USE_PKGSRC.mail:M[yY][eE][sS])
TOOLS_DEPENDS.mail?=		heirloom-mailx-[0-9]*:../../mail/heirloom-mailx
TOOLS_CREATE+=			mail
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mail=heirloom-mailx
TOOLS_PATH.mail=		${TOOLS_PREFIX.mail}/bin/mailx
.  endif
.endif

.if !defined(TOOLS_IGNORE.makeinfo) && !empty(_USE_TOOLS:Mmakeinfo)
.  if !empty(PKGPATH:Mdevel/gtexinfo)
MAKEFLAGS+=			TOOLS_IGNORE.makeinfo=
.  elif !empty(_TOOLS_USE_PKGSRC.makeinfo:M[yY][eE][sS])
TOOLS_DEPENDS.makeinfo?=	gtexinfo>=${TEXINFO_REQD}:../../devel/gtexinfo
TOOLS_CREATE+=			makeinfo
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.makeinfo=gtexinfo
TOOLS_PATH.makeinfo=		${TOOLS_PREFIX.makeinfo}/bin/makeinfo
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
TOOLS_DEPENDS.mtree?=		mtree>=20040722:../../pkgtools/mtree
TOOLS_CREATE+=			mtree
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mtree=mtree
TOOLS_PATH.mtree=		${TOOLS_PREFIX.mtree}/bin/mtree
.  endif
.endif

.if !defined(TOOLS_IGNORE.openssl) && !empty(_USE_TOOLS:Mopenssl)
#
# Ensure we use pkgsrc openssl if we're not using builtin.
#
CHECK_BUILTIN.openssl:=		yes
.  include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=		no
.  if !empty(USE_BUILTIN.openssl:M[nN][oO])
_TOOLS_USE_PKGSRC.openssl=	yes
.  endif
.  if !empty(PKGPATH:Msecurity/openssl)
MAKEFLAGS+=			TOOLS_IGNORE.openssl=
.  elif !empty(_TOOLS_USE_PKGSRC.openssl:M[yY][eE][sS])
TOOLS_DEPENDS.openssl?=		openssl>=0.9.6:../../security/openssl
TOOLS_CREATE+=			openssl
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.openssl=openssl
TOOLS_PATH.openssl=		${TOOLS_PREFIX.openssl}/bin/openssl
.  endif
.endif

.if !defined(TOOLS_IGNORE.patch) && !empty(_USE_TOOLS:Mpatch)
.  if !empty(PKGPATH:Mdevel/patch)
MAKEFLAGS+=			TOOLS_IGNORE.patch=
.  elif !empty(_TOOLS_USE_PKGSRC.patch:M[yY][eE][sS])
TOOLS_DEPENDS.patch?=		nbpatch-[0-9]*:../../devel/nbpatch
TOOLS_CREATE+=			patch
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.patch=nbpatch
TOOLS_PATH.patch=		${TOOLS_PREFIX.patch}/bin/nbpatch
_PATCH_CAN_BACKUP=		yes
_PATCH_BACKUP_ARG=		-V simple -z
.  endif
.endif

.if !defined(TOOLS_IGNORE.pax) && !empty(_USE_TOOLS:Mpax)
.  if !empty(PKGPATH:Marchivers/pax)
MAKEFLAGS+=			TOOLS_IGNORE.pax=
.  elif !empty(_TOOLS_USE_PKGSRC.pax:M[yY][eE][sS])
TOOLS_DEPENDS.pax?=		pax>=20040802:../../archivers/pax
TOOLS_CREATE+=			pax
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pax=pax
TOOLS_PATH.pax=			${TOOLS_PREFIX.pax}/bin/${NBPAX_PROGRAM_PREFIX}pax
.  endif
.endif

.if !defined(TOOLS_IGNORE.pkg-config) && !empty(_USE_TOOLS:Mpkg-config)
.  if !empty(PKGPATH:Mdevel/pkg-config)
MAKEFLAGS+=			TOOLS_IGNORE.pkg-config=
.  elif !empty(_TOOLS_USE_PKGSRC.pkg-config:M[yY][eE][sS])
TOOLS_DEPENDS.pkg-config?=	pkg-config>=0.25:../../devel/pkg-config
TOOLS_CREATE+=			pkg-config
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.pkg-config=pkg-config
TOOLS_PATH.pkg-config=		${TOOLS_PREFIX.pkg-config}/bin/pkg-config
.  else
AUTORECONF_ARGS+=		-I ${TOOLS_PLATFORM.pkg-config:S/\/bin\/pkg-config//}/share/aclocal
.  endif
.endif

.if !defined(TOOLS_IGNORE.rpm2pkg) && !empty(_USE_TOOLS:Mrpm2pkg)
.  if !empty(PKGPATH:Mpkgtools/rpm2pkg)
MAKEFLAGS+=			TOOLS_IGNORE.rpm2pkg=
.  elif !empty(_TOOLS_USE_PKGSRC.rpm2pkg:M[yY][eE][sS])
TOOLS_DEPENDS.rpm2pkg?=		rpm2pkg>=3.1.4:../../pkgtools/rpm2pkg
TOOLS_CREATE+=			rpm2pkg
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.rpm2pkg=rpm2pkg
TOOLS_PATH.rpm2pkg=		${TOOLS_PREFIX.rpm2pkg}/sbin/rpm2pkg
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
TOOLS_DEPENDS.tar?=		pax>=20040802:../../archivers/pax
TOOLS_CREATE+=			tar
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.tar=pax
TOOLS_PATH.tar=			${TOOLS_PREFIX.tar}/bin/${NBPAX_PROGRAM_PREFIX}tar
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

.if !defined(TOOLS_IGNORE.texi2html) && !empty(_USE_TOOLS:Mtexi2html)
.  if !empty(PKGPATH:Mtextproc/texi2html)
MAKEFLAGS+=			TOOLS_IGNORE.texi2html=
.  elif !empty(_TOOLS_USE_PKGSRC.texi2html:M[yY][eE][sS])
TOOLS_DEPENDS.texi2html?=	texi2html>=1.76:../../textproc/texi2html
TOOLS_CREATE+=			texi2html
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.texi2html=texi2html
TOOLS_PATH.texi2html=		${TOOLS_PREFIX.texi2html}/bin/texi2html
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
TOOLS_DEPENDS.type1inst?=	type1inst>=0.6.1:../../fonts/type1inst
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

.if !defined(TOOLS_IGNORE.wget) && !empty(_USE_TOOLS:Mwget)
.  if !empty(PKGPATH:Mnet/wget)
MAKEFLAGS+=			TOOLS_IGNORE.wget=
.  elif !empty(_TOOLS_USE_PKGSRC.wget:M[yY][eE][sS])
TOOLS_DEPENDS.wget?=		wget-[0-9]*:../../net/wget
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.wget=wget
TOOLS_PATH.wget=		${TOOLS_PREFIX.wget}/bin/wget
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
TOOLS_PATH.xargs=		${TOOLS_PREFIX.xargs}/bin/gxargs
TOOLS_ARGS.xargs=		-r	# don't run command if stdin is empty
.  endif
.endif

_TOOLS.xz=	xz xzcat
.for _t_ in ${_TOOLS.xz}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Marchivers/xz)
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=		xz>=4.999.9betanb1:../../archivers/xz
TOOLS_CREATE+=			${_t_}
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.${_t_}=xz
TOOLS_PATH.${_t_}=		${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

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

_TOOLS.zip=	zip zipcloak zipnote zipsplit
.for _t_ in ${_TOOLS.zip}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Marchivers/zip)
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=		zip-[0-9]*:../../archivers/zip
TOOLS_CREATE+=			${_t_}
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.${_t_}=zip
TOOLS_PATH.${_t_}=		${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by the lang/perl5 package if there is
# no native tool available.
#
_TOOLS.perl=			perl perldoc pod2html pod2man pod2text

.for _t_ in ${_TOOLS.perl}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mlang/perl5)
MAKEFLAGS+=			TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS]) || \
     !empty(DEPENDS:Mp5-*) || !empty(PERL5_PREFIX:M${PREFIX})
.      include "../../lang/perl5/version.mk"
_TOOLS_USE_PKGSRC.perl=		yes
TOOLS_DEPENDS.${_t_}?=		perl>=${PERL5_REQD}:../../lang/perl5
TOOLS_CREATE+=			${_t_}
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.${_t_}=perl
TOOLS_PATH.${_t_}=		${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor

# These tools are all supplied by the sysutils/coreutils package if
# there is no native tool available.
#
_TOOLS.coreutils=	basename cat chgrp chmod chown cp cut date	\
		dirname echo env expr false head hostname id install	\
		ln ls mkdir mv nice numfmt printf pwd readlink realpath \
		rm rmdir sleep sort tail tee test touch tr true tsort wc

.for _t_ in ${_TOOLS.coreutils}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	coreutils>=5.2.1:../../sysutils/coreutils
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=coreutils
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/g${_t_}
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
TOOLS_PATH.[=		${TOOLS_PREFIX.[}/bin/g[
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
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/g${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are supplied by textproc/mdocml as replacements for their
# groff counterparts.  As this package has fewer dependencies it should
# be preferred over groff wherever possible.
#
_TOOLS.mdocml=	nroff

.for _t_ in ${_TOOLS.mdocml}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mtextproc/mdocml)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	mdocml>=1.12.0nb3:../../textproc/mdocml
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=mdocml
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/mandoc
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by the textproc/groff package if there is
# no native tool available.
#
_TOOLS.groff=	groff soelim tbl

.for _t_ in ${_TOOLS.groff}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mtextproc/groff)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    else
.      if defined(_TOOLS_USE_PKGSRC.groff) && \
        !empty(_TOOLS_USE_PKGSRC.groff:M[yY][eE][sS])
_TOOLS_USE_PKGSRC.${_t_}= yes
.      endif
.      if !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	groff>=1.19.2nb3:../../textproc/groff
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=groff
.        if ${OPSYS} == "SunOS" && "${_t_}" != "groff"
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/g${_t_}
.        else
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.        endif
.      endif
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
.    if ${OPSYS} == "SunOS"
TOOLS_PATH.gsoelim=	${TOOLS_PREFIX.gsoelim}/bin/gsoelim
.    else
TOOLS_PATH.gsoelim=	${TOOLS_PREFIX.gsoelim}/bin/soelim
.    endif
.  endif
TOOLS_ALIASES.gsoelim=	soelim
.endif

######################################################################

# These tools are all supplied by the devel/diffutils package if there is
# no native tool available.
#
_TOOLS.diffutils=	cmp diff diff3 sdiff

.for _t_ in ${_TOOLS.diffutils}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mdevel/diffutils)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	diffutils>=2.8.1:../../devel/diffutils
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=diffutils
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/g${_t_}
.    endif
.  endif
.endfor

######################################################################

# These tools are all supplied by a Ghostscript package if there is no
# native tool available.
#
_TOOLS.ghostscript=	dvipdf gs pdf2ps ps2pdf

# This is the minimum version of Ghostscript required by the current
# package.
#
GHOSTSCRIPT_REQD?=	6.01

# Set TOOLS_DEPENDS.ghostscript to an appropriate dependency based on
# various package options.
#
.if !defined(TOOLS_DEPENDS.ghostscript)
_TOOLS_DEP.ghostscript:=	ghostscript
TOOLS_DEPENDS.ghostscript=	ghostscript>=${GHOSTSCRIPT_REQD}:../../print/ghostscript
MAKEVARS+=			TOOLS_DEPENDS.ghostscript
.endif

.for _t_ in ${_TOOLS.ghostscript}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mprint/ghostscript) || \
        !empty(PKGPATH:Mprint/ghostscript-esp)
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

# For modular Xorg, these are individual packages.
#
.if !defined(TOOLS_IGNORE.iceauth) && !empty(_USE_TOOLS:Miceauth)
.  if !empty(PKGPATH:Mx11/iceauth)
MAKEFLAGS+=		TOOLS_IGNORE.iceauth=
.  elif !empty(_TOOLS_USE_PKGSRC.iceauth:M[yY][eE][sS])
TOOLS_CREATE+=			iceauth
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.iceauth=	${X11BASE}/bin/iceauth
.    else
TOOLS_DEPENDS.iceauth?=		iceauth-[0-9]*:../../x11/iceauth
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.iceauth=iceauth
TOOLS_PATH.iceauth=		${TOOLS_PREFIX.iceauth}/bin/iceauth
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.mkfontdir) && !empty(_USE_TOOLS:Mmkfontdir)
.  if !empty(PKGPATH:Mfonts/mkfontdir)
MAKEFLAGS+=		TOOLS_IGNORE.mkfontdir=
.  elif !empty(_TOOLS_USE_PKGSRC.mkfontdir:M[yY][eE][sS])
TOOLS_CREATE+=			mkfontdir
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.mkfontdir=	${X11BASE}/bin/mkfontdir
.    else
TOOLS_DEPENDS.mkfontdir?=	mkfontdir-[0-9]*:../../fonts/mkfontdir
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mkfontdir=mkfontdir
TOOLS_PATH.mkfontdir=		${TOOLS_PREFIX.mkfontdir}/bin/mkfontdir
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.mkfontscale) && !empty(_USE_TOOLS:Mmkfontscale)
.  if !empty(PKGPATH:Mfonts/mkfontscale)
MAKEFLAGS+=		TOOLS_IGNORE.mkfontscale=
.  elif !empty(_TOOLS_USE_PKGSRC.mkfontscale:M[yY][eE][sS])
TOOLS_CREATE+=			mkfontscale
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.mkfontscale=	${X11BASE}/bin/mkfontscale
.    else
TOOLS_DEPENDS.mkfontscale?=	mkfontscale-[0-9]*:../../fonts/mkfontscale
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.mkfontscale=mkfontscale
TOOLS_PATH.mkfontscale=		${TOOLS_PREFIX.mkfontscale}/bin/mkfontscale
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.bdftopcf) && !empty(_USE_TOOLS:Mbdftopcf)
.  if !empty(PKGPATH:Mfonts/bdftopcf)
MAKEFLAGS+=		TOOLS_IGNORE.bdftopcf=
.  elif !empty(_TOOLS_USE_PKGSRC.bdftopcf:M[yY][eE][sS])
TOOLS_CREATE+=			bdftopcf
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.bdftopcf=	${X11BASE}/bin/bdftopcf
.    else
TOOLS_DEPENDS.bdftopcf?=	bdftopcf-[0-9]*:../../fonts/bdftopcf
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bdftopcf=bdftopcf
TOOLS_PATH.bdftopcf=		${TOOLS_PREFIX.bdftopcf}/bin/bdftopcf
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.ucs2any) && !empty(_USE_TOOLS:Mucs2any)
.  if !empty(PKGPATH:Mfonts/font-util)
MAKEFLAGS+=		TOOLS_IGNORE.ucs2any=
.  elif !empty(_TOOLS_USE_PKGSRC.ucs2any:M[yY][eE][sS])
TOOLS_CREATE+=			ucs2any
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.ucs2any=	${X11BASE}/bin/ucs2any
.    else
TOOLS_DEPENDS.ucs2any?=		font-util-[0-9]*:../../fonts/font-util
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.ucs2any=ucs2any
TOOLS_PATH.ucs2any=		${TOOLS_PREFIX.ucs2any}/bin/ucs2any
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.bdftruncate) && !empty(_USE_TOOLS:Mbdftruncate)
.  if !empty(PKGPATH:Mfonts/font-util)
MAKEFLAGS+=		TOOLS_IGNORE.bdftruncate=
.  elif !empty(_TOOLS_USE_PKGSRC.bdftruncate:M[yY][eE][sS])
TOOLS_CREATE+=			bdftruncate
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.bdftruncate=	${X11BASE}/bin/bdftruncate
.    else
TOOLS_DEPENDS.bdftruncate?=	font-util-[0-9]*:../../fonts/font-util
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.bdftruncate=bdftruncate
TOOLS_PATH.bdftruncate=		${TOOLS_PREFIX.bdftruncate}/bin/bdftruncate
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.xauth) && !empty(_USE_TOOLS:Mxauth)
.  if !empty(PKGPATH:Mx11/xauth)
MAKEFLAGS+=		TOOLS_IGNORE.xauth=
.  elif !empty(_TOOLS_USE_PKGSRC.xauth:M[yY][eE][sS])
TOOLS_CREATE+=			xauth
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.xauth=	${X11BASE}/bin/xauth
.    else
TOOLS_DEPENDS.xauth?=		xauth-[0-9]*:../../x11/xauth
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.xauth=xauth
TOOLS_PATH.xauth=		${TOOLS_PREFIX.xauth}/bin/xauth
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.xinit) && !empty(_USE_TOOLS:Mxinit)
.  if !empty(PKGPATH:Mx11/xinit)
MAKEFLAGS+=		TOOLS_IGNORE.xinit=
.  elif !empty(_TOOLS_USE_PKGSRC.xinit:M[yY][eE][sS])
TOOLS_CREATE+=			xinit
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.xinit=	${X11BASE}/bin/xinit
.    else
TOOLS_DEPENDS.xinit?=		xinit-[0-9]*:../../x11/xinit
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.xinit=xinit
TOOLS_PATH.xinit=		${TOOLS_PREFIX.xinit}/bin/xinit
.    endif
.  endif
.endif

.if !defined(TOOLS_IGNORE.xmessage) && !empty(_USE_TOOLS:Mxmessage)
.  if !empty(PKGPATH:Mx11/xmessage)
MAKEFLAGS+=		TOOLS_IGNORE.xmessage=
.  elif !empty(_TOOLS_USE_PKGSRC.xmessage:M[yY][eE][sS])
TOOLS_CREATE+=			xmessage
.    if !empty(X11_TYPE:Mnative)
TOOLS_PATH.xmessage=	${X11BASE}/bin/xmessage
.    else
TOOLS_DEPENDS.xmessage?=		xmessage-[0-9]*:../../x11/xmessage
TOOLS_FIND_PREFIX+=		TOOLS_PREFIX.xmessage=xmessage
TOOLS_PATH.xmessage=		${TOOLS_PREFIX.xmessage}/bin/xmessage
.    endif
.  endif
.endif

######################################################################

# These tools are all supplied by an X11 imake package if there is no
# native tool available.
#
_TOOLS.x11-imake=	imake mkdirhier xmkmf

.for _t_ in ${_TOOLS.x11-imake}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(_USE_TOOLS:M${_t_})
.    if !empty(PKGPATH:Mdevel/nbitools) || \
	!empty(PKGPATH:Mx11/xorg-imake)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_CREATE+=		${_t_}
.      if !empty(_USE_TOOLS:Mitools)
TOOLS_DEPENDS.${_t_}?=	nbitools>=6.3nb4:../../devel/nbitools
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=nbitools
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/libexec/itools/${_t_}
.      else
TOOLS_DEPENDS.${_t_}?=	imake-[0-9]*:../../devel/imake
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=imake
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.      endif
.    endif
.  endif
.endfor

.if !defined(TOOLS_IGNORE.makedepend) && !empty(_USE_TOOLS:Mmakedepend)
.  if !empty(PKGPATH:Mdevel/nbitools) || \
	!empty(PKGPATH:Mx11/xorg-imake)
MAKEFLAGS+=		TOOLS_IGNORE.makedepend=
.  elif !empty(_TOOLS_USE_PKGSRC.makedepend:M[yY][eE][sS])
TOOLS_CREATE+=		makedepend
.    if !empty(_USE_TOOLS:Mitools)
TOOLS_DEPENDS.makedepend?=	nbitools>=6.3nb4:../../devel/nbitools
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.makedepend=nbitools
TOOLS_PATH.makedepend=	${TOOLS_PREFIX.makedepend}/libexec/itools/makedepend
.    elif defined(X11_TYPE) && !empty(X11_TYPE:Mmodular)
TOOLS_DEPENDS.makedepend?=	makedepend-[0-9]*:../../devel/makedepend
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.makedepend=makedepend
TOOLS_PATH.makedepend=	${TOOLS_PREFIX.makedepend}/bin/makedepend
.    else # !empty(X11_TYPE:Mnative)
TOOLS_PATH.makedepend=	${X11BASE}/bin/makedepend
.    endif
.  endif
.endif

######################################################################

# Compute the locations of the pkgsrc-supplied tools.
FIND_PREFIX:=	${TOOLS_FIND_PREFIX}
.include "../find-prefix.mk"

######################################################################

.for _t_ in ${_USE_TOOLS}
.  if !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS]) && \
      !defined(TOOLS_IGNORE.${_t_})
#####
##### Add the dependencies for each pkgsrc-supplied tool.
#####
.    if defined(_TOOLS_DEPMETHOD.${_t_}) && defined(TOOLS_DEPENDS.${_t_})
.      for _dep_ in ${TOOLS_DEPENDS.${_t_}}
_dep_test := ${_dep_:C/\:.*$//}
.        if empty(${_TOOLS_DEPMETHOD.${_t_}}:C/\:.*$//:M${_dep_test})
${_TOOLS_DEPMETHOD.${_t_}}+=	${_dep_}
.        endif
.      endfor
.    endif
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

# Create a TOOLS_ENV variable that holds a shell environment that
# defines all of the "TOOL" variables for use within a shell.  This
# shell environment may need to be passed to the configure or build
# phases since these paths may be hardcoded into package scripts, and
# if they're not pre-specified, then they'll be searched for in the
# PATH, which would find the ones in ${TOOLS_DIR}.

# For packages that use GNU configure scripts, pass the appropriate
# environment variables to ensure the proper command is invoked for
# each tool.  The value passed via the shell environment is stored in
# TOOLS_VALUE_GNU.<tool>, which defaults to the full command line of
# the tool.
#
.if defined(GNU_CONFIGURE)
.  for _t_ in ${_USE_TOOLS}
.    if defined(TOOLS_${_TOOLS_VARNAME.${_t_}})
TOOLS_VALUE_GNU.${_t_}?=	${TOOLS_CMDLINE.${_t_}}
.    endif
.    if defined(TOOLS_VALUE_GNU.${_t_})
.      for _v_ in ${_TOOLS_VARNAME_GNU.${_t_}}
TOOLS_ENV+=	${_v_}=${TOOLS_VALUE_GNU.${_t_}:Q}
.      endfor
.    endif
.  endfor
CONFIGURE_ENV+=	${TOOLS_ENV}
.endif

# For packages that do not use GNU configure scripts, pass the full
# command-line for each tool used.
#
.if !defined(GNU_CONFIGURE)
.  for _t_ in ${_USE_TOOLS}
.    for _v_ in ${_TOOLS_VARNAME.${_t_}}
TOOLS_ENV+=	${_v_}=${TOOLS_CMDLINE.${_t_}:Q}
.    endfor
.  endfor
.endif
