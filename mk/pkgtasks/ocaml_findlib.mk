# $NetBSD: ocaml_findlib.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the ocaml_findlib package task.

# OCAML_FINDLIB_REGISTER
#	Package-settable variable for whether to automatically update
#	the OCaml findlib ld.conf file.
#
#	Possible: yes, no
#	Default: yes
#
_PKG_VARS.pkgtasks+=		OCAML_FINDLIB_REGISTER
OCAML_FINDLIB_REGISTER?=	yes

# OCAML_FINDLIB_DIRS
#	List of directories relative to ${OCAML_SITELIBDIR} that should
#	be added or removed from the findlib ld.conf file.
#
# OCAML_SITELIBDIR
#	Path relative to ${PREFIX} that contains the installed OCaml
#	packages.  This variable is set by ocaml.mk.
#
#	Default: lib/ocaml/site-lib
#
_PKG_VARS.pkgtasks+=	OCAML_FINDLIB_DIRS
_SYS_VARS.pkgtasks+=	OCAML_SITELIBDIR
OCAML_FINDLIB_DIRS?=	# empty
OCAML_SITELIBDIR?=	lib/ocaml/site-lib
FILES_SUBST+=		OCAML_SITELIB=${OCAML_SITELIBDIR:Q}

# Trigger pkgtasks dependency if needed.
.if "${OCAML_FINDLIB_REGISTER:tl}" == "yes"
_PKGTASKS_DATAVARS.ocaml_findlib=	OCAML_FINDLIB_DIRS
.  for _var_ in ${_PKGTASKS_DATAVARS.ocaml_findlib}
.    if !empty(${_var_})
USE_PKGTASKS=		yes
.    endif
.  endfor
.endif

# Strip leading "${PREFIX}/" from directory pathnames.
_OCAML_FINDLIB_DIRS=	${OCAML_FINDLIB_DIRS:S|^${PREFIX}/${OCAML_SITELIBDIR}/||g}

_PKGTASKS_DATA.ocaml_findlib=	${_PKGTASKS_DIR}/ocaml_findlib
_PKGTASKS_DATAFILES+=		${_PKGTASKS_DATA.ocaml_findlib}

# Only emit FINDLIB data lines if ${OCAML_FINDLIB_REGISTER} is "yes.
${_PKGTASKS_DATA.ocaml_findlib}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}${TEST} "${OCAML_FINDLIB_REGISTER:tl}" = "yes" || exit 0;	\
	set -- args ${_OCAML_FINDLIB_DIRS}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		libdir="$$1"; shift;					\
		${ECHO} "# FINDLIB: $$libdir" >> ${.TARGET}.tmp;	\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
