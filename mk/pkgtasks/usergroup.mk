# $NetBSD: usergroup.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the groups package task.

# PKG_CREATE_USERGROUP
#	Whether to automatically update the system groups database.
#
#	Possible: yes, no
#	Default: yes
#
_USER_VARS.pkgtasks+=	PKG_CREATE_USERGROUP
PKG_CREATE_USERGROUP?=	yes
FILES_SUBST+=		PKG_CREATE_USERGROUP=${PKG_CREATE_USERGROUP:Q}

# USERGROUP_PHASE
#	The phase just before which users and groups need to be created.
#	If not defined or empty, then by default, users and groups are
#	created when the binary package is installed as part of the
#	package tasks invoked.
#
#	Possible: configure, build, pre-install
#	Default: (empty)
#
_PKG_VARS.pkgtasks+=	USERGROUP_PHASE
USERGROUP_PHASE?=	# empty
_USERGROUP_PHASES=	configure build pre-install

.if !empty(USERGROUP_PHASE) && empty(_USERGROUP_PHASES:M${USERGROUP_PHASE})
PKG_FAIL_REASON+=	"USERGROUP_PHASE must be one of: ${_USERGROUP_PHASES}"
.endif

# PKG_GROUPS
#	List of group names that should be added or removed from the
#	system group database.
#
# PKG_GID.<group>
#	The numeric group ID for the named group.  If not defined or
#	empty, then this variable is set by the infrastructure and it
#	may be used in phases after and including ${USERGROUP_PHASE}.
#
#	Possible: any valid group ID
#	Default: (empty)
#
# PKG_USERS
#	List of pairs of usernames and group names for users that
#	should be added or removed from the system users database.  The
#	pairs are of the form: <user>:<group>.
#
# PKG_UID.<user>
#	The numeric user ID for the named user.  If not defined or
#	empty, then this variable is set by the infrastructure if
#	${USERGROUP_PHASE} is non-empty, and it may be used in phases
#	after and including ${USERGROUP_PHASE}.
#
#	Possible: any valid user ID
#	Default: (empty)
#
# PKG_GECOS.<user>
#	The description for the user.
#
#	Possible: any string not containing ':' (colon, ASCII 58)
#	Default: (empty)
#
# PKG_HOME.<user>
#	The home directory for the user.
#
#	Possible: any valid pathname
#	Default: ${_PKG_USER_HOME} (set in platform/${OPSYS}.mk)
#
# PKG_SHELL.<user>
#	The login shell for the user.
#
#	Possible: any login shell
#	Default: ${_PKG_USER_SHELL) (set in platform/${OPSYS}.mk)
#
_PKG_VARS.pkgtasks+=	PKG_GROUPS PKG_USERS
_PKG_VARS.pkgtasks+=	${PKG_GROUPS:@g@PKG_GID.${g}@}
_PKG_VARS.pkgtasks+=	${PKG_USERS:@u@PKG_UID.${u:C/\:.*$//}@}
_PKG_VARS.pkgtasks+=	${PKG_USERS:@u@PKG_GECOS.${u:C/\:.*$//}@}
_PKG_VARS.pkgtasks+=	${PKG_USERS:@u@PKG_HOME.${u:C/\:.*$//}@}
_PKG_VARS.pkgtasks+=	${PKG_USERS:@u@PKG_SHELL.${u:C/\:.*$//}@}

PKG_GROUP?=		# empty
PKG_USERS?=		# empty

_PKG_USER_HOME?=	/nonexistent
_PKG_USER_SHELL?=	${NOLOGIN}
FILES_SUBST+=		PKG_USER_HOME=${_PKG_USER_HOME:Q}
FILES_SUBST+=		PKG_USER_SHELL=${_PKG_USER_SHELL:Q}

.if !empty(PKG_USERS:N*\:*)
PKG_FAIL_REASON+=	${PKG_USERS:N*\:*:Q}" in PKG_USERS should be <user>:<group>"
.endif

# USE_GAMESGROUP
#	Whether the package uses a "games" group.  If ${USE_GAMESGROUP}
#	is "yes", then the following variables may be used when
#	installing setgid games and their data files:
#	
#	GAMES_USER
#	GAMES_GROUP
#	GAMEMODE
#	SETGID_GAMES_PERMS
#
# SETGIDGAME is deprecated, but use its value if USE_GAMESGROUP is not
# defined.
#
_PKG_VARS.pkgtasks+=	USE_GAMEGROUP
#USE_GAMESGROUP?=	# empty
USE_GAMESGROUP?=	${SETGIDGAME}
.if ${USE_GAMESGROUP:tl} == "yes"
PKG_GROUPS+=	${GAMES_GROUP}
PKG_USERS+=	${GAMES_USER}:${GAMES_GROUP}
_BUILD_DEFS+=	GAMES_GROUP GAMES_USER GAMEDATAMODE GAMEDIRMODE GAMEMODE
.endif

.if !defined(OPSYS) && !empty(OPSYS:MInterix)
.  for _user_ in ${PKG_USERS:C/\\\\//g:C/:.*//}
.    if !empty(PKG_GROUPS:M${_user_})
PKG_FAIL_REASON+=	"User and group '${_user_}' cannot be the same name on Interix".
.    endif
.  endfor
.endif

# Trigger dependency on pkgtasks if needed.
_PKGTASKS_DATAVARS.groups=	PKG_GROUPS
_PKGTASKS_DATAVARS.users=	PKG_USERS
.for _var_ in ${_PKGTASKS_DATAVARS.groups} ${_PKGTASKS_DATAVARS.users}
.  if !empty(${_var_})
USE_PKGTASKS=		yes
.  endif
.endfor

# Add dependency on useradd/groupadd package as needed.
# TODO: Implement more platforms' useradd and groupadd in "pkgtasks".
#
.if !empty(PKG_USERS) || !empty(PKG_GROUPS)
DEPENDS+=	${_USER_DEPENDS}
.endif

# Shell commands used to determine the numeric GIDs and UIDs of
# groups and users on the system.
#
_GETGID_CMD?=	${PERL5} -le 'print scalar getgrnam shift'
_GETUID_CMD?=	${PERL5} -le 'print scalar getpwnam shift'

# Split out ${_PKG_GROUP.<user>} for each entry in ${PKG_USERS}.
_PKG_USERS=		${PKG_USERS:C/:.*$//}
.for _entry_ in ${PKG_USERS}
.  for _user_ in ${_entry_:C/:.*$//g}
_PKG_GROUP.${_user_}=	${_entry_:C/^.*://g}
.  endfor
.endfor

.if !empty(USERGROUP_PHASE)
.  for _group_ in ${PKG_GROUPS}
_USERGROUP_TOOLS=	perl
PKG_GID.${_group_}?=	${_PKG_GID.${_group_}}
_PKG_GID.${_group_}=	${_PKG_GID.${_group_}_cmd:sh:M*}
_PKG_GID.${_group_}_cmd=	\
	( ${_GETGID_CMD} ${_group_:Q} ) 2>/dev/null || ${ECHO} ""
.  endfor
.  for _user_ in ${_PKG_USERS}
_USERGROUP_TOOLS=	perl
PKG_UID.${_user_}?=	${_PKG_UID.${_user_}}
_PKG_UID.${_user_}=	${_PKG_UID.${_user_}_cmd:sh:M*}
_PKG_UID.${_user_}_cmd=	\
	( ${_GETUID_CMD} ${_user_:Q} ) 2>/dev/null || ${ECHO} ""
.  endfor
_PKG_GROUPDATA=		${PKG_GROUPS:@g@${g:Q}:${PKG_GID.${g}:Q}@:C/:*$//g}
_PKG_USERDATA=		${_PKG_USERS:@u@${u:Q}:${_PKG_GROUP.${u}:Q}:${PKG_UID.${u}:Q}:${PKG_GECOS.${u}:Q}:${PKG_HOME.${u}:U${_PKG_USER_HOME}:Q}:${PKG_SHELL.${u}:U${_PKG_USER_SHELL}:Q}@:C/:*$//g}
_USERGROUP_EXISTS=	\
	( set -- args \
	  	${PKG_GROUPS:@g@${_PKG_GID.${g}:Q}"" ${PKG_GID.${g}:Q}""@} \
		${_PKG_USERS:@u@${_PKG_UID.${u}:Q}"" ${PKG_UID.${u}:Q}""@}; \
	  shift; while [ $$\# -gt 0 ]; do \
	  	real="$$1"; requested="$$2"; shift 2; \
	  	[ -n "$$real" -a "$$real" = "$$requested" ] || exit 1; \
	  done; exit 0 )

.else
_PKG_GROUPDATA=		${PKG_GROUPS}
_PKG_USERDATA=		${_PKG_USERS:@u@${u:Q}:${_PKG_GROUP.${u}:Q}::${PKG_GECOS.${u}:Q}:${PKG_HOME.${u}:U${_PKG_USER_HOME}:Q}:${PKG_SHELL.${u}:U${_PKG_USER_SHELL}:Q}@:C/:*$//g}
_USERGROUP_EXISTS=	( : "make create-usergroup"; exit 1 )
.endif

_USERGROUP_TOOLS?=	# empty
USE_TOOLS+=		${_USERGROUP_TOOLS}

_PKGTASKS_DATA.groups=	${_PKGTASKS_DIR}/groups
_PKGTASKS_DATAFILES+=	${_PKGTASKS_DATA.groups}

${_PKGTASKS_DATA.groups}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}set -- args ${_PKG_GROUPDATA}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		entry="$$1"; shift;					\
		${ECHO} "# GROUP: $$entry" >> ${.TARGET}.tmp;		\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}

_PKGTASKS_DATA.users=	${_PKGTASKS_DIR}/users
_PKGTASKS_DATAFILES+=	${_PKGTASKS_DATA.users}

${_PKGTASKS_DATA.users}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}set -- args ${_PKG_USERDATA}; shift;				\
	while ${TEST} "$$#" -gt 0; do					\
		entry="$$1"; shift;					\
		${ECHO} "# USER: $$entry" >> ${.TARGET}.tmp;		\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}

# create-usergroup
#	make(1) target to create any required groups and users.
#
.PHONY: create-usergroup
create-usergroup: su-target
	@${STEP_MSG} "Requiring users and groups for "${PKGNAME:Q}

_PKGTASKS_USERGROUP=	${PKGSRCDIR}/mk/pkgtasks/usergroup.sh
_PKGTASKS_ENV=		PKGNAME=${PKGNAME:Q}				\
			PKG_CREATE_USERGROUP=${PKG_CREATE_USERGROUP:Q}	\
			PKG_PREFIX=${PREFIX:Q}				\
			PKG_REFCOUNT_DBDIR=${PKG_REFCOUNT_DBDIR:Q}	\
			TASK_MODULE_DIR=${TASK_MODULE_DIR:Q}		\
			TASK_PLATFORM=${OPSYS:Q}

PRE_CMD.su-create-usergroup=	\
	if ${_USERGROUP_EXISTS}; then \
		${ECHO} "All groups and users already exist."; \
		exit 0; \
	fi

.PHONY: su-create-usergroup
su-create-usergroup: ${_PKGTASKS_DATA.groups} ${_PKGTASKS_DATA.users}
	${RUN}${SETENV} ${_PKGTASKS_ENV} ${SH} ${_PKGTASKS_USERGROUP:Q} \
		${_PKGTASKS_DATA.groups:Q} ${_PKGTASKS_DATA.users:Q}

.if !empty(USERGROUP_PHASE:Mconfigure)
pre-configure: create-usergroup
.elif !empty(USERGROUP_PHASE:Mbuild)
pre-build: create-usergroup
.elif !empty(USERGROUP_PHASE:Mpre-install)
pre-install: create-usergroup
.endif
