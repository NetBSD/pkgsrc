# $NetBSD: shells.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the shells package task.

# PKG_REGISTER_SHELLS
#	Whether to automatically update the /etc/shells database.
#
#	Possible: yes, no
#	Default: yes
#
_USER_VARS.pkgtasks+=	PKG_REGISTER_SHELLS
PKG_REGISTER_SHELLS?=	yes
FILES_SUBST+=		PKG_REGISTER_SHELLS=${PKG_REGISTER_SHELLS:Q}

# PKG_SHELL
#	List of shell pathnames that should be added or removed from
#	the shell database, /etc/shells.  If a pathname is a relative
#	path, then it is taken to be relative to ${PREFIX}.
#
_PKG_VARS.pkgtasks+=	PKG_SHELL
PKG_SHELL?=		# empty

# Trigger pkgtasks dependency if needed.
_PKGTASKS_DATAVARS.shells=	PKG_SHELL
.for _var_ in ${_PKGTASKS_DATAVARS.shells}
.  if !empty(${_var_})
USE_PKGTASKS=		yes
.  endif
.endfor

# Strip leading "${PREFIX}/" from shell pathname.
_PKG_SHELL=		${PKG_SHELL:S|^${PREFIX}/||g}

_PKGTASKS_DATA.shells=	${_PKGTASKS_DIR}/shells
_PKGTASKS_DATAFILES+=	${_PKGTASKS_DATA.shells}

${_PKGTASKS_DATA.shells}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}set -- args ${_PKG_SHELL}; shift;				\
	while ${TEST} "$$#" -gt 0; do					\
		shell="$$1"; shift;					\
		${ECHO} "# SHELL: $$shell" >> ${.TARGET}.tmp;		\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
