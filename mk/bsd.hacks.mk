# $NetBSD: bsd.hacks.mk,v 1.4 2018/08/22 20:48:36 maya Exp $
#
# Copyright (c) 2004 The NetBSD Foundation, Inc.
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

# This Makefile fragment automatically includes the necessary hacks to
# make the package build correctly by including the package's hacks.mk
# file if it exists.
#
# An example package hacks.mk:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# .if !defined(FOO_HACKS_MK)
# FOO_HACKS_MK=	defined
#
# ### [Sun Nov 14 02:08:31 EST 2004 : jlam]
# ### arm GCC 2.95.x optimisation bug tickled when compiling
# ### lib/funkyfile.c.  Require a more recent version of GCC as a
# ### workaround and patch lib/funkyfile.c (patch-ae).
# ###
# .if !empty(MACHINE_ARCH:Marm*)
# PKG_HACKS+=	optimisation
# GCC_REQD+=	3.0
# .endif
#
# .endif  # FOO_HACKS_MK
# -------------8<-------------8<-------------8<-------------8<-------------

PKG_HACKS?=	# empty

.if exists(${PKGDIR}/hacks.mk)
.  include "${PKGDIR}/hacks.mk"
.endif

# Record any package hacks that we use in the installed package.
.if !empty(PKG_HACKS)
_BUILD_DEFS+=	PKG_HACKS
.endif
