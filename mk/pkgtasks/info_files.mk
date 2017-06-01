# $NetBSD: info_files.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the info_files package task.

# INFO_DIR
#	The location of the directory containing the "dir" index file
#	to be updated.  If the location is a relative path, then it
#	is taken to be relative to ${PREFIX}.
#
#	Possible: any path
#	Default: (empty)
#
_PKG_VARS.pkgtasks+=	INFO_DIR
INFO_DIR?=		# empty

# Strip leading "${PREFIX}/" from the directory pathname.
_INFO_DIR=		${INFO_DIR:S|^${PREFIX}/||g}

# INFO_FILES
#	Whether the package has GNU info files that need to trigger an
#	update of the "dir" index files.
#
#	Possible: set, or unset
#	Default: unset
#
_PKG_VARS.pkgtasks+=	INFO_FILES

.if defined(INFO_FILES)
USE_TOOLS+=		install-info:run
FILES_SUBST+=		INSTALL_INFO=${INSTALL_INFO:Q}
USE_PKGTASKS=		yes	# trigger pkgtasks dependency if needed
.endif

_PKGTASKS_DATA.info_files=	${_PKGTASKS_DIR}/info_files
_PKGTASKS_DATAFILES+=		${_PKGTASKS_DATA.info_files}

# ${INFO_FILES_cmd} is defined by the plist module.
${_PKGTASKS_DATA.info_files}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
.if defined(INFO_FILES)
	${RUN}${INFO_FILES_cmd} |					\
	while IFS= read file; do					\
		infodir=${_INFO_DIR:Q};					\
		case $$infodir in					\
		"")	${ECHO} "# INFO: $$file" ;;			\
		*)	${ECHO} "# INFO: $$file $$infodir" ;;		\
		esac;							\
	done > ${.TARGET:Q}.tmp
.else
	${RUN}exec > ${.TARGET:Q}.tmp
.endif
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
