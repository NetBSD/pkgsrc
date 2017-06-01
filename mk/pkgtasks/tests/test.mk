# $NetBSD: test.mk,v 1.1 2017/06/01 02:06:05 jlam Exp $
#
# Copyright (c) 2017 The NetBSD Foundation, Inc.
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

# Definitions used by pkgtasks/*.mk files that are not assigned default
# values.
#
_PKGTASKS_DIR?=		${WRKDIR}/.pkgtasks
CAT?=			cat
CP?=			cp
ECHO?=			echo
FAIL_MSG?=		${ECHO} "!!!"
LOCALBASE?=		/usr/pkg
MKDIR?=			mkdir -p
MV?=			mv
NOLOGIN?=		/sbin/nologin
PKG_SYSCONFDIR?=	/etc
PREFIX?=		${LOCALBASE}
RM?=			rm
RUN?=			@
SH?=			/bin/sh
STEP_MSG?=		${ECHO} ">>>"
TEST?=			test
VARBASE?=		/var

_PKGTASKS_NEEDARGS=							\
	needargs() {							\
		if ${TEST} $$3 -lt $$2; then				\
			${FAIL_MSG} "$$1 must have a multiple of $$2 words. Rest: $$4"; \
			return 1;					\
		fi;							\
	}

# Override any other default definitions so that generated files go into
# the current directory.
#
WRKDIR=		${.CURDIR}

.PHONY: all
all: _all

.PHONY: _all
_all:
	${RUN}: "do nothing"
