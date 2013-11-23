# $NetBSD: bsd.builtin.mk,v 1.13 2013/11/23 09:06:09 obache Exp $
#
# Copyright (c) 2004-2005 The NetBSD Foundation, Inc.
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

# Include this file to set the value of USE_BUILTIN.<pkg> for each
# package listed in BUILDLINK_TREE.  Note that this file may
# indirectly add additional values to BUILDLINK_TREE.
#
# For each package which may duplicate built-in software on the system,
# a builtin.mk file should be created.  The only requirements of a
# builtin.mk file are:
#
#   (1) It should set USE_BUILTIN.<pkg> to either "yes" or "no" after it
#       is included.
#   (2) It should *not* override any USE_BUILTIN.<pkg> which is already
#       set before the builtin.mk file is included.
#   (3) It should be written to allow multiple inclusion.
#
# An example package builtin.mk file is:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILTIN_PKG:=	wibble
# .include "../../mk/buildlink3/bsd.builtin.mk"
#
# ###
# ### Determine if there is a built-in implementation of the package and
# ### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
# ###
# .if !defined(IS_BUILTIN.wibble)
# IS_BUILTIN.wibble=	no
# .endif
# MAKEVARS+=	IS_BUILTIN.wibble
#
# ###
# ### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
# ### a package name to represent the built-in package.
# ###
# .if !defined(BUILTIN_PKG.wibble) && \
#     !empty(IS_BUILTIN.wibble:M[yY][eE][sS])
# BUILTIN_PKG.wibble=	wibble-1.0
# .endif
# MAKEVARS+=	BUILTIN_PKG.wibble
#
# ###
# ### Determine whether we should use the built-in implementation if it
# ### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
# ###
# .if !defined(USE_BUILTIN.wibble)
# .  if ${PREFER.wibble} == "pkgsrc"
# USE_BUILTIN.wibble=	no
# .  else
# USE_BUILTIN.wibble=	${IS_BUILTIN.wibble}
# .    if defined(BUILTIN_PKG.wibble) && \
#         !empty(IS_BUILTIN.wibble:M[yY][eE][sS])
# USE_BUILTIN.wibble=	yes
# .      for _dep_ in ${BUILDLINK_API_DEPENDS.wibble}
# .        if !empty(USE_BUILTIN.wibble:M[yY][eE][sS])
# USE_BUILTIN.wibble!=							\
#	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.wibble:Q}; then	\
#		${ECHO} "yes";						\
#	else								\
#		${ECHO} "no";						\
#	fi
# .        endif
# .      endfor
# .    endif
# .  endif
# .endif
# MAKEVARS+=	USE_BUILTIN.wibble
#
# ###
# ### The section below only applies if we are not including this file
# ### solely to determine whether a built-in implementation exists.
# ###
# CHECK_BUILTIN.wibble?=	no
# .if !empty(CHECK_BUILTIN.wibble:M[nN][oO])
# #
# # Here we place code that depends on whether USE_BUILTIN.wibble is
# # set to "yes" or "no".
# #
# .endif  # CHECK_BUILTIN.wibble
# -------------8<-------------8<-------------8<-------------8<-------------
#
# Note the structure of the builtin.mk file: first we set IS_BUILTIN.<pkg>,
# then USE_BUILTIN.<pkg>, then we isolate code that depends on the whether
# USE_BUILTIN.<pkg> is "yes" or "no" in a region that is guarded by
# CHECK_BUILTIN.<pkg>.  Package builtin.mk files aren't protected against
# multiple inclusion.
#

.include "../../mk/bsd.fast.prefs.mk"

.for _pkg_ in ${BUILTIN_PKG}
#
# Define PREFER.<pkg> to be either "pkgsrc" or "native" depending on whether
# to prefer the pkgsrc or native version of a particular package.  Its value
# is determined by a number of variables described below.
#
# PREFER.<pkg>
#	This variable has the highest precedence, and should generally only be
#	used by packages when it is known that a specific version should always
#	be used or avoided.
#
# PREFER_PKGSRC
# PREFER_NATIVE
#	These user-settable variables either take "yes" or a list of package
#	names.  The "yes" form has a lower precedence than a specific package,
#	so the most common case is to set one variable to "yes" and then override
#	specific packages in the other variable.
#
#	If a package is specified in neither or in both variables, then the
#	PREFER_PKGSRC setting takes precedence.
#
# _OPSYS_PREFER.<pkg>
#	This variable should only be set in mk/platform files, and provides a
#	per-platform default that takes precedence over "yes" in PREFER_* but is
#	overridden by a more specific package name match.
#
_BLTN_PREFER.${_pkg_}=	pkgsrc
.  if !empty(PREFER_NATIVE:M[yY][eE][sS])
_BLTN_PREFER.${_pkg_}=	native
.  endif
.  if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_BLTN_PREFER.${_pkg_}=	pkgsrc
.  endif
.  if defined(_OPSYS_PREFER.${_pkg_})
_BLTN_PREFER.${_pkg_}=	${_OPSYS_PREFER.${_pkg_}}
.  endif
.  if !empty(PREFER_NATIVE:M${_pkg_})
_BLTN_PREFER.${_pkg_}=	native
.  endif
.  if !empty(PREFER_PKGSRC:M${_pkg_})
_BLTN_PREFER.${_pkg_}=	pkgsrc
.  endif
PREFER.${_pkg_}?=	${_BLTN_PREFER.${_pkg_}}
.  if empty(_BUILTIN_PKGS:M${_pkg_})
_BUILTIN_PKGS+=	${_pkg_}
.  endif
.endfor

.include "../../mk/buildlink3/find-libs.mk"
.include "../../mk/buildlink3/find-headers.mk"
.include "../../mk/buildlink3/find-files.mk"
