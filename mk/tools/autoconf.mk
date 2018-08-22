# $NetBSD: autoconf.mk,v 1.20 2018/08/22 20:48:37 maya Exp $
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
# This Makefile fragment handles packages that use GNU autoconf.
#
# By default, all of the autoconf-related scripts are marked as
# "missing" by running the GNU missing script in place of the utility.
# This hides the autoconf-related scripts from makefiles that aggressively
# call them when some of the inputs are modified in ways the makefiles
# don't expect.
#
# If a package needs to use GNU autoconf, then the package Makefile
# should contain one of the following lines:
#
#	USE_TOOLS+=	autoconf	# use recent GNU autoconf (>=2.50)
#	USE_TOOLS+=	autoconf213	# use GNU autoconf ~2.13
#
# This will allow the package to invoke "autoconf", "autoreconf", etc.
# by their usual, bare names.
#
# If a particular minimum version of autoconf is required, then the
# package Makefile can additionally set AUTOCONF_REQD to the desired
# version, e.g.:
#
#	AUTOCONF_REQD=	2.54	# use at least autoconf>=2.54
#
# To globally prevent any GNU autoconf handling, set the following
# in the package Makefile:
#
#	AUTOMAKE_OVERRIDE=	no
#
# Keywords: autoconf

# If a package requires autoreconf, the package Makefile should contain
# this line:
#
#	USE_TOOLS+=	autoreconf autoconf automake
#
# Keywords: autoreconf

# Only allow one of "autoconf" and "autoconf213" in USE_TOOLS.
.if !empty(USE_TOOLS:C/:.*//:Mautoconf) && \
    !empty(USE_TOOLS:C/:.*//:Mautoconf213)
PKG_FAIL_REASON+=	"\`\`autoconf'' and \`\`autoconf213'' conflict in USE_TOOLS."
.endif

# This is an exhaustive list of all of the scripts supplied by GNU
# autoconf.
#
_TOOLS_AC_NAMES=	autoconf	autoconf-2.13
_TOOLS_AC_NAMES+=	autoheader	autoheader-2.13
_TOOLS_AC_NAMES+=	autom4te
_TOOLS_AC_NAMES+=	autoreconf	autoreconf-2.13
_TOOLS_AC_NAMES+=	autoscan	autoscan-2.13
_TOOLS_AC_NAMES+=	autoupdate	autoupdate-2.13
_TOOLS_AC_NAMES+=	ifnames		ifnames-2.13

.for _t_ in ${_TOOLS_AC_NAMES}
_TOOLS_AC_TYPE.${_t_}?=	TOOLS_GNU_MISSING
.endfor _t_

.if !defined(TOOLS_IGNORE.autoconf) && !empty(USE_TOOLS:C/:.*//:Mautoconf)
.  if !empty(PKGPATH:Mdevel/autoconf)
MAKEFLAGS+=		TOOLS_IGNORE.autoconf=
.  else
AUTOCONF_REQD?=		2.50

.    if !empty(USE_TOOLS:Mautoconf\:run)
_TOOLS_DEPMETHOD.autoconf=	DEPENDS
.    else
_TOOLS_DEPMETHOD.autoconf=	TOOL_DEPENDS
.    endif
TOOLS_DEPENDS.autoconf?=	autoconf>=${AUTOCONF_REQD}:../../devel/autoconf
.    if empty(${_TOOLS_DEPMETHOD.autoconf}:M${TOOLS_DEPENDS.autoconf})
${_TOOLS_DEPMETHOD.autoconf}+=	${TOOLS_DEPENDS.autoconf}
.    endif

_TOOLS_AC_TYPE.autoconf=	TOOLS_CREATE
TOOLS_PATH.autoconf=		${LOCALBASE}/bin/autoconf

_TOOLS_AC_TYPE.autoheader=	TOOLS_CREATE
TOOLS_PATH.autoheader=		${LOCALBASE}/bin/autoheader

_TOOLS_AC_TYPE.autom4te=	TOOLS_CREATE
TOOLS_PATH.autom4te=		${LOCALBASE}/bin/autom4te

_TOOLS_AC_TYPE.autoreconf=	TOOLS_CREATE
TOOLS_PATH.autoreconf=		${LOCALBASE}/bin/autoreconf

_TOOLS_AC_TYPE.autoscan=	TOOLS_CREATE
TOOLS_PATH.autoscan=		${LOCALBASE}/bin/autoscan

_TOOLS_AC_TYPE.autoupdate=	TOOLS_CREATE
TOOLS_PATH.autoupdate=		${LOCALBASE}/bin/autoupdate

_TOOLS_AC_TYPE.ifnames=		TOOLS_CREATE
TOOLS_PATH.ifnames=		${LOCALBASE}/bin/ifnames
.  endif
.endif

.if !defined(TOOLS_IGNORE.autoconf213) && !empty(USE_TOOLS:C/:.*//:Mautoconf213)
.  if !empty(PKGPATH:Mdevel/autoconf213)
MAKEFLAGS+=		TOOLS_IGNORE.autoconf213=
.  else
AUTOCONF_REQD?=		2.13

.    if !empty(USE_TOOLS:Mautoconf213\:run)
_TOOLS_DEPMETHOD.autoconf213=	DEPENDS
.    else
_TOOLS_DEPMETHOD.autoconf213=	TOOL_DEPENDS
.    endif
TOOLS_DEPENDS.autoconf213?=	autoconf213>=${AUTOCONF_REQD}:../../devel/autoconf213
.    if empty(${_TOOLS_DEPMETHOD.autoconf213}:M${TOOLS_DEPENDS.autoconf213})
${_TOOLS_DEPMETHOD.autoconf213}+=	${TOOLS_DEPENDS.autoconf213}
.    endif

_TOOLS_AC_TYPE.autoconf-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.autoconf=	# empty
TOOLS_PATH.autoconf-2.13=	${LOCALBASE}/bin/autoconf-2.13
TOOLS_ALIASES.autoconf-2.13=	autoconf

_TOOLS_AC_TYPE.autoheader-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.autoheader=	# empty
TOOLS_PATH.autoheader-2.13=	${LOCALBASE}/bin/autoheader-2.13
TOOLS_ALIASES.autoheader-2.13=	autoheader

_TOOLS_AC_TYPE.autoreconf-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.autoreconf=	# empty
TOOLS_PATH.autoreconf-2.13=	${LOCALBASE}/bin/autoreconf-2.13
TOOLS_ALIASES.autoreconf-2.13=	autoreconf

_TOOLS_AC_TYPE.autoscan-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.autoscan=	# empty
TOOLS_PATH.autoscan-2.13=	${LOCALBASE}/bin/autoscan-2.13
TOOLS_ALIASES.autoscan-2.13=	autoscan

_TOOLS_AC_TYPE.autoupdate-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.autoupdate=	# empty
TOOLS_PATH.autoupdate-2.13=	${LOCALBASE}/bin/autoupdate-2.13
TOOLS_ALIASES.autoupdate-2.13=	autoupdate

_TOOLS_AC_TYPE.ifnames-2.13=	TOOLS_CREATE
_TOOLS_AC_TYPE.ifnames=		# empty
TOOLS_PATH.ifnames-2.13=	${LOCALBASE}/bin/ifnames-2.13
TOOLS_ALIASES.ifnames-2.13=	ifnames

.    if defined(USE_LIBTOOL)
pre-configure: tools-libtool-m4-override
.    endif
.  endif
.endif

# If the package wants to override the GNU auto* tools, then do it.
AUTOMAKE_OVERRIDE?=	yes
.if !empty(AUTOMAKE_OVERRIDE:M[yY][eE][sS])
.  for _t_ in ${_TOOLS_AC_NAMES}
.    if !empty(_TOOLS_AC_TYPE.${_t_})
${_TOOLS_AC_TYPE.${_t_}}+=	${_t_}
.    endif
.  endfor
.endif

# LIBTOOL_M4_OVERRIDE lists the locations where the libtool.m4 symlink
# will be created.  The libtool.m4 symlink is only created if a GNU
# configure script exists at that location.
#
LIBTOOL_M4_OVERRIDE?=	libtool.m4 */libtool.m4 */*/libtool.m4

# Symlink the libtool-1.4.m4 file into any directory in which there's
# a configure script under ${WRKSRC}.  The symlink is called "libtool.m4",
# which is the name expected by the autoconf tools.  The symlinking
# is only done if we need autoconf-2.13 and libtool.  This allows
# autoconf-2.13, autoreconf-2.13 and aclocal-2.13 to use the older
# libtool.m4 file when regenerating files.  This is okay, because we
# later override the generated libtool file anyway.
#
.PHONY: tools-libtool-m4-override
tools-libtool-m4-override:
.for _pattern_ in ${LIBTOOL_M4_OVERRIDE}
	${RUN}								\
	cd ${WRKSRC};							\
	for cfile in ${_pattern_:S/libtool.m4$/configure/}; do		\
		if ${TEST} -f "$$cfile"; then				\
			libtool_m4=`${DIRNAME} $$cfile`/libtool.m4;	\
			${LN} -sf ${PKGSRCDIR}/mk/gnu-config/libtool-1.4.m4 \
				$$libtool_m4;				\
		fi;							\
	done
.endfor
