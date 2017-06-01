# $NetBSD: permissions.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the permissions package task.

# SPECIAL_PERMS
#	List of blocks of four words of the following form:
#
#		<file> <owner> <group> <mode>
#
#	The <file> (it may be a directory) is changed to be owned by
#	<owner>:<group> with <mode> permissions.  If <file> is a
#	relative path, then it is taken to be relative to ${PREFIX}.
#
#	SPECIAL_PERMS should be used primarily to change permissions of
#	files or directories listed in the PLIST.  This may be used to
#	ensure certain files are set-uid or to change the ownership of a
#	directory.
#
_PKG_VARS.pkgtasks+=	SPECIAL_PERMS
SPECIAL_PERMS?=		# empty

# Trigger pkgtasks dependency if needed.
_PKGTASKS_DATAVARS.permissions=	SPECIAL_PERMS
.for _var_ in ${_PKGTASKS_DATAVARS.permissions}
.  if !empty(${_var_})
USE_PKGTASKS=		yes
.  endif
.endfor

# Strip leading "${PREFIX}/" from pathnames.
_SPECIAL_PERMS=		${SPECIAL_PERMS:S|^${PREFIX}/||g}

# SETUID_ROOT_PERMS
#	Convenience variable used to note an executable should be setuid
#	root, and should be used as follows:
#
#	SPECIAL_PERMS+=	/path/to/suidroot ${SETUID_ROOT_PERMS}
#
# SETGID_GAMES_PERMS
#	Convenience variable used to note an executable should be setgid
#	games, and should be used as follows:
#
#	SPECIAL_PERMS+=	/path/to/sgidgame ${SETGID_GAMES_PERMS}
#
# GAMEDATA_PERMS
# GAMEDIR_PERMS
#	Convenience variables for files or directories that should be
#	accessible by executables that are setgid games.  Since such
#	files or directories should normally live under ${VARBASE},
#	these definitions should be used roughly as follows:
#
#	REQD_DIRS_PERMS+=  /path/to/scoredir ${GAMEDIR_PERMS}
#	REQD_FILES_PERMS+= /dev/null /path/to/scorefile ${GAMEDATA_PERMS}
#
# Keywords: setuid setgid st_mode perms
#
_SYS_VARS.pkgtasks+=	SETUID_ROOT_PERMS SETGID_GAMES_PERMS \
			GAMEDATA_PERMS GAMEDIR_PERMS
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4511
SETGID_GAMES_PERMS?=	${GAMES_USER} ${GAMES_GROUP} ${GAMEMODE}
GAMEDATA_PERMS?=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
GAMEDIR_PERMS?=		${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

# Assert that the variables have the right number of words.
.for _var_ in SPECIAL_PERMS
.  if empty(${_var_}) || empty(${_var_}:C/.*/4/:M*:S/4 4 4 4//gW)
# ${_var_} has a multiple of 4 words.
.  else
PKG_FAIL_REASON+=	${_var_:Q}" must have a multiple of 4 words."
.  endif
.endfor

_PKGTASKS_DATA.permissions=	${_PKGTASKS_DIR}/permissions
_PKGTASKS_DATAFILES+=		${_PKGTASKS_DATA.permissions}

${_PKGTASKS_DATA.permissions}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}set -- args ${_SPECIAL_PERMS}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		path="$$1"; owner="$$2"; group="$$3"; mode="$$4"; shift 4; \
		${ECHO} "# PERMS: $$path $$mode $$owner $$group"	\
			>> ${.TARGET}.tmp;				\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
