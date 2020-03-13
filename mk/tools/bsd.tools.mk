# $NetBSD: bsd.tools.mk,v 1.60 2020/03/13 17:33:02 rillig Exp $
#
# Copyright (c) 2005, 2006 The NetBSD Foundation, Inc.
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

# This Makefile fragment is included to bsd.pkg.mk and defines the
# relevant variables and targets for the "tools" phase.
#
# The following are the "public" targets provided by this module:
#
#    tools
#

# Prepend ${TOOLS_DIR}/bin to the PATH so that our scripts are found
# first when searching for executables.
#
TOOLS_DIR=	${WRKDIR}/.tools
PREPEND_PATH+=	${TOOLS_DIR}/bin

TOOLS_SHELL?=		${SH}
_TOOLS_WRAP_LOG=	${WRKLOG}

USE_TOOLS?=		# empty

_COOKIE.tools=	${WRKDIR}/.tools_done

######################################################################
### tools (PUBLIC)
######################################################################
### tools is a public target to create a private directory of tools
### specified by USE_TOOLS.
###
_TOOLS_TARGETS+=	check-vulnerable
_TOOLS_TARGETS+=	acquire-tools-lock
_TOOLS_TARGETS+=	${_COOKIE.tools}
_TOOLS_TARGETS+=	release-tools-lock

.PHONY: tools
.if !target(tools)
.  if exists(${_COOKIE.tools}) && !${_CLEANING}
tools:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
tools: ${_TOOLS_TARGETS}
.  else
tools: barrier
.  endif
.endif

.PHONY: acquire-tools-lock release-tools-lock
acquire-tools-lock: acquire-lock
release-tools-lock: release-lock

.if exists(${_COOKIE.tools}) && !${_CLEANING}
${_COOKIE.tools}:
	@${DO_NADA}
.else
${_COOKIE.tools}: real-tools
.endif

######################################################################
### real-tools (PRIVATE)
######################################################################
### real-tools is a helper target onto which one can hook all of the
### targets that do the actual tool creation.
###
_REAL_TOOLS_TARGETS+=	tools-message
_REAL_TOOLS_TARGETS+=	tools-vars
_REAL_TOOLS_TARGETS+=	override-tools
_REAL_TOOLS_TARGETS+=	post-tools
_REAL_TOOLS_TARGETS+=	tools-cookie
_REAL_TOOLS_TARGETS+=	error-check

.PHONY: real-tools
real-tools: ${_REAL_TOOLS_TARGETS}

.PHONY: tools-message
tools-message:
	@${PHASE_MSG} "Overriding tools for ${PKGNAME}"

######################################################################
### tools-cookie (PRIVATE)
######################################################################
### tools-cookie creates the "tools" cookie file.  The contents
### are the names of the tools in USE_TOOLS.
###
.PHONY: tools-cookie
tools-cookie:
	${RUN} ${TEST} ! -f ${_COOKIE.tools} || ${FALSE}
	${RUN} ${MKDIR} ${_COOKIE.tools:H}
	${RUN} ${ECHO} ${USE_TOOLS:Q} > ${_COOKIE.tools}

######################################################################
### override-tools (PRIVATE)
######################################################################
### override-tools is a helper target onto which one can hook all of
### the targets that create tools so they are generated at the proper
### time.
###
.PHONY: override-tools
override-tools:
	@${DO_NADA}

######################################################################
### post-tools (PUBLIC, override)
######################################################################
### post-tools may be overridden within a package Makefile and can be
### used to directly modify the contents of the tools directory after
### the tools are generated.
###
.PHONY: post-tools
.if !target(post-tools)
post-tools:
	@${DO_NADA}
.endif

.include "digest.mk"
.include "automake.mk"
.include "autoconf.mk"
.include "texinfo.mk"
.include "gettext.mk"
.include "flex.mk"
.include "bison.mk"
.include "gmake.mk"
.include "intltool.mk"
.include "ldconfig.mk"
.include "rpcgen.mk"
.include "strip.mk"
.include "cmake.mk"
.include "imake.mk"
.include "zip.mk"
.include "replace.mk"
.include "perl.mk"
.include "pkg-config.mk"
.include "make.mk"

.include "create.mk"

_VARGROUPS+=		tools
_USER_VARS.tools=	TOOLS_SHELL
_PKG_VARS.tools=	USE_TOOLS TOOLS_BROKEN TOOLS_CREATE \
	TOOLS_FAIL TOOLS_GNU_MISSING TOOLS_NOOP
.for t in ${USE_TOOLS:C/:.*//:O:u}
.  for pv in \
	TOOLS_PLATFORM \
	TOOLS_PATH \
	TOOLS_CMD \
	TOOLS_ARGS \
	TOOLS_SCRIPT \
	TOOLS_SCRIPT_DFLT \
	TOOLS_ALIASES \
	TOOLS_DEPENDS \
	TOOLS_IGNORE \
	TOOLS_VALUE_GNU \
	# nil
_SYS_VARS.tools+=	${pv}.${t}
.  endfor
.endfor
_SORTED_VARS.tools=	USE_TOOLS TOOLS_CREATE TOOLS_GNU_MISSING
