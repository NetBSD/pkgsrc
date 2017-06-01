# $NetBSD: rc.d.mk,v 1.1 2017/06/01 02:08:04 jlam Exp $
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

# Infrastructure support for the rc.d script system (pkgtools/rc.subr).
#
# Package-settable variables:
#
# RCD_SCRIPTS
#	List of the basenames of the rc.d scripts.  The example rc.d
#	script must be found in ${PREFIX}/share/examples/rc.d, and
#	the script will be copied into ${RCD_SCRIPTS_DIR} with
#	${RCD_SCRIPTS_MODE} permissions.
#
# RCD_SCRIPTS_DIR
#	The location of the copied rc.d scripts.
#
#	Possible: any path
#	Default: /etc/rc.d
#
# RCD_SCRIPTS_EXAMPLEDIR
#	The location of the example rc.d scripts.  This location must
#	be a relative path to ${PREFIX}.
#
#	Possible: any path
#	Default: share/examples/rc.d
#
# RCD_SCRIPTS_MODE
#	The file mode of the copied rc.d scripts.
#
#	Possible: any file mode
#	Default: 0755
#
# RCD_SCRIPTS_SHELL
#	The shell used to run the rc.d scripts.
#
#	Possible: any shell path
#	Default: ${SH}
#
# RCD_SCRIPT_SRC.<script>
#	The source file for the rc.d script with basename <script>
#	before installation; the source file is put through variable
#	substitution to generate the target rc.d script.  If the
#	source file is not present, then no rc.d script is generated.
#
#	Possible: any path
#	Default: ${FILESDIR}/<script>.sh
#
_PKG_VARS.init+=	RCD_SCRIPTS RCD_SCRIPTS_MODE RCD_SCRIPTS_SHELL
_PKG_VARS.init+=	RCD_SCRIPTS_DIR RCD_SCRIPTS_EXAMPLEDIRI
_PKG_VARS.init+=	${RCD_SCRIPTS:@s@RCD_SCRIPT_SRC.${s}@}

RCD_SCRIPTS_DIR?=		/etc/rc.d
RCD_SCRIPTS_EXAMPLEDIR?=	share/examples/rc.d
RCD_SCRIPTS_MODE?=		0755
RCD_SCRIPTS_SHELL?=		${SH}

FILES_SUBST+=		RCD_SCRIPTS_SHELL=${RCD_SCRIPTS_SHELL:Q}
MESSAGE_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:Q}
MESSAGE_SUBST+=		RCD_SCRIPTS_EXAMPLEDIR=${RCD_SCRIPTS_EXAMPLEDIR:Q}

.PHONY: generate-rcd-scripts
generate-rcd-scripts:	# do nothing

# Hook into installation process via "post-install" target.
.PHONY: install-rcd-scripts
post-install: install-rcd-scripts
install-rcd-scripts:	# do nothing

# Add to MAKE_DIRS to ensure ${RCD_SCRIPTS_DIR} is created automatically.
_MAKE_RCD_SCRIPTS_DIR=	# empty

.for _script_ in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${_script_}?=	${FILESDIR}/${_script_}.sh
_RCD_SCRIPT_WRK.${_script_}?=	${WRKDIR}/.rc.d/${_script_}
_RCD_SCRIPT_FILE.${_script_}?=	${RCD_SCRIPTS_EXAMPLEDIR}/${_script_}

.  if !empty(RCD_SCRIPT_SRC.${_script_})
generate-rcd-scripts: ${_RCD_SCRIPT_WRK.${_script_}}
${_RCD_SCRIPT_WRK.${_script_}}: ${RCD_SCRIPT_SRC.${_script_}}
	@${STEP_MSG} "Creating "${.TARGET:Q}
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}${CAT} ${.ALLSRC:Q} | ${SED} ${FILES_SUBST_SED} > ${.TARGET:Q}
	${RUN}${CHMOD} +x ${.TARGET:Q}

.PHONY: install-rcd-${_script_}
install-rcd-scripts: install-rcd-${_script_}
install-rcd-${_script_}: ${_RCD_SCRIPT_WRK.${_script_}}
	${RUN}${MKDIR} ${DESTDIR:Q}${PREFIX:Q}/${_RCD_SCRIPT_FILE.${_script_}:H:Q}
	${RUN}${INSTALL_SCRIPT} ${_RCD_SCRIPT_WRK.${_script_}} \
		${DESTDIR:Q}${PREFIX:Q}/${_RCD_SCRIPT_FILE.${_script_}:Q}
.  endif

# Hook into plist module to automatically add rc.d scripts into the
# packing list.
#
GENERATE_PLIST+=	${ECHO} ${_RCD_SCRIPT_FILE.${_script_}:Q};
PRINT_PLIST_AWK+=	/^${_RCD_SCRIPT_FILE.${_script_}:S|/|\\/|g}/ { next; }

# Hook into the pkgtasks module to copy rc.d scripts into place in
# the package tasks.
#
_INIT_SCRIPTS+=		${_RCD_SCRIPT_FILE.${_script_}} \
			${RCD_SCRIPTS_DIR}/${_script_}
_INIT_SCRIPTS_MODE=	${RCD_SCRIPTS_MODE}

# Only set this value if ${RCD_SCRIPTS} was non-empty.
_MAKE_RCD_SCRIPTS_DIR=	${RCD_SCRIPTS_DIR}
.endfor

# Hook into the pkgtasks module to create ${RCD_SCRIPTS_DIR} in the
# package tasks if there are rc.d scripts to copy into place.
#
MAKE_DIRS+=	${_MAKE_RCD_SCRIPTS_DIR}
