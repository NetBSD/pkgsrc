# $NetBSD: bsd.pkg.install.mk,v 1.57 2004/04/27 03:30:04 tv Exp $
#
# This Makefile fragment is included by bsd.pkg.mk to use the common
# INSTALL/DEINSTALL scripts.  To use this Makefile fragment, simply:
#
# (1) Set the variables to customize the install scripts to the package, and
# (2) Set USE_PKGINSTALL in the package Makefile.
#
# NOTE: This file must _not_ be included from anything else than bsd.pkg.mk.

.if !defined(BSD_PKG_INSTALL_MK)
BSD_PKG_INSTALL_MK=	1

.include "../../mk/bsd.prefs.mk"

DEINSTALL_FILE=		${WRKDIR}/.DEINSTALL
INSTALL_FILE=		${WRKDIR}/.INSTALL

# These are the template scripts for the INSTALL/DEINSTALL scripts.  Packages
# may do additional work in the INSTALL/DEINSTALL scripts by overriding the
# variables DEINSTALL_EXTRA_TMPL and INSTALL_EXTRA_TMPL to point to
# additional script fragments.  These bits are included after the main
# install/deinstall script fragments.  Packages may also override the
# variables DEINSTALL_TMPL and INSTALL_TMPL to completely customize the
# install/deinstall logic.
#
_HEADER_TMPL?=		${.CURDIR}/../../mk/install/header
.if !defined(HEADER_EXTRA_TMPL) && exists(${.CURDIR}/HEADER)
HEADER_EXTRA_TMPL?=	${.CURDIR}/HEADER
.else
HEADER_EXTRA_TMPL?=	# empty
.endif
DEINSTALL_PRE_TMPL?=	${.CURDIR}/../../mk/install/deinstall-pre
DEINSTALL_EXTRA_TMPL?=	# empty
DEINSTALL_TMPL?=	${.CURDIR}/../../mk/install/deinstall
INSTALL_TMPL?=		${.CURDIR}/../../mk/install/install
INSTALL_EXTRA_TMPL?=	# empty
INSTALL_POST_TMPL?=	${.CURDIR}/../../mk/install/install-post
_FOOTER_TMPL?=		${.CURDIR}/../../mk/install/footer

# DEINSTALL_TEMPLATES and INSTALL_TEMPLATES are the default list of source
#	files that are concatenated to form the DEINSTALL/INSTALL scripts.
#
DEINSTALL_TEMPLATES=	${_HEADER_TMPL}
DEINSTALL_TEMPLATES+=	${HEADER_EXTRA_TMPL}
DEINSTALL_TEMPLATES+=	${DEINSTALL_PRE_TMPL}
DEINSTALL_TEMPLATES+=	${DEINSTALL_EXTRA_TMPL}
DEINSTALL_TEMPLATES+=	${DEINSTALL_TMPL}
DEINSTALL_TEMPLATES+=	${_FOOTER_TMPL}
INSTALL_TEMPLATES=	${_HEADER_TMPL}
INSTALL_TEMPLATES+=	${HEADER_EXTRA_TMPL}
INSTALL_TEMPLATES+=	${INSTALL_TMPL}
INSTALL_TEMPLATES+=	${INSTALL_EXTRA_TMPL}
INSTALL_TEMPLATES+=	${INSTALL_POST_TMPL}
INSTALL_TEMPLATES+=	${_FOOTER_TMPL}

# These are the list of source files that are concatenated to form the
# INSTALL/DEINSTALL scripts.
#
DEINSTALL_SRC?=		${DEINSTALL_TEMPLATES}
INSTALL_SRC?=		${INSTALL_TEMPLATES}

# FILES_SUBST lists what to substitute in DEINSTALL/INSTALL scripts and in
# rc.d scripts.
#
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		LOCALBASE=${LOCALBASE}
FILES_SUBST+=		X11BASE=${X11BASE}
FILES_SUBST+=		DEPOTBASE=${DEPOTBASE}
FILES_SUBST+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}
FILES_SUBST+=		PKG_SYSCONFDEPOTBASE=${PKG_SYSCONFDEPOTBASE}
FILES_SUBST+=		PKG_SYSCONFBASEDIR=${PKG_SYSCONFBASEDIR}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=		CONF_DEPENDS=${CONF_DEPENDS:C/:.*//:Q}
FILES_SUBST+=		PKGBASE=${PKGBASE}
FILES_SUBST+=		PKG_INSTALLATION_TYPE=${PKG_INSTALLATION_TYPE}

# PKG_USERS represents the users to create for the package.  It is a
#	space-separated list of elements of the form
#
#		user:group[:[userid][:[descr][:[home][:shell]]]]
#
#	Only the user and group are required; everything else is optional,
#	but the colons must be in the right places when specifying optional
#	bits.  Note that if the description contains spaces, then spaces
#	should be double backslash-escaped, e.g.
#
#		foo:foogrp::The\\ Foomister
#
# PKG_GROUPS represents the groups to create for the package.  It is a
#	space-separated list of elements of the form
#
#		group[:groupid]
#
#	Only the group is required; the groupid is optional.
#
PKG_USERS?=		# empty
_PKG_USER_HOME?=	/nonexistent
_PKG_USER_SHELL?=	${NOLOGIN}
PKG_GROUPS?=		# empty
FILES_SUBST+=		PKG_USERS=${PKG_USERS:Q}
FILES_SUBST+=		PKG_USER_HOME=${_PKG_USER_HOME}
FILES_SUBST+=		PKG_USER_SHELL=${_PKG_USER_SHELL}
FILES_SUBST+=		PKG_GROUPS=${PKG_GROUPS:Q}

.if !empty(PKG_USERS)
USE_USERADD=		YES
.endif
.if !empty(PKG_GROUPS)
USE_GROUPADD=		YES
.endif

# SPECIAL_PERMS are lists that look like:
#		file user group mode
#	At post-install time, file (it may be a directory) is changed to be
#	owned by user:group with mode permissions.
#
# SPECIAL_PERMS should be used primarily to change permissions of files or
# directories listed in the PLIST.  This may be used to make certain files
# set-uid or to change the ownership or a directory.
#
# SETUID_ROOT_PERMS is a convenience definition to note an executable is
# meant to be setuid-root, and should be used as follows:
#
#	SPECIAL_PERMS+=	/path/to/suidroot ${SETUID_ROOT_PERMS}
#
SPECIAL_PERMS?=		# empty
SETUID_ROOT_PERMS?=	${ROOT_USER} ${ROOT_GROUP} 4711
FILES_SUBST+=		SPECIAL_PERMS=${SPECIAL_PERMS:Q}

# CONF_FILES are pairs of example and true config files, used much like
#	MLINKS in the base system.  At post-install time, if the true config
#	file doesn't exist, then the example one is copied into place.  At
#	deinstall time, the true one is removed if it doesn't differ from the
#	example one.  SUPPORT_FILES is used the same way, but the package
#	admin isn't prompted to customize the file at post-install time.
#
# CONF_FILES_MODE and SUPPORT_FILES_MODE are the file permissions for the
#	files in CONF_FILES and SUPPORT_FILES, respectively.
#
# CONF_FILES_PERMS are lists that look like:
#		example_file config_file user group mode
#	and works like CONF_FILES, except the config files are owned by
#	user:group have mode permissions.  SUPPORT_FILES_PERMS is used in the
#	same way, but the package admin isn't prompted to customize the file
#	at post-install time.
#
# RCD_SCRIPTS works lists the basenames of the rc.d scripts.  They are
#	expected to be found in ${RCD_SCRIPTS_EXAMPLEDIR}, and the scripts
#	will be copied into ${RCD_SCRIPTS_DIR} with ${RCD_SCRIPTS_MODE}
#	permissions.
#
CONF_FILES?=		# empty
CONF_FILES_MODE?=	0644
CONF_FILES_PERMS?=	# empty
SUPPORT_FILES?=		# empty
SUPPORT_FILES_MODE?=	0644
SUPPORT_FILES_PERMS?=	# empty
RCD_SCRIPTS?=		# empty
RCD_SCRIPTS_MODE?=	0755
RCD_SCRIPTS_EXAMPLEDIR?=	${PREFIX}/etc/rc.d
RCD_SCRIPTS_SHELL?=	${SH}
FILES_SUBST+=		CONF_FILES=${CONF_FILES:Q}
FILES_SUBST+=		CONF_FILES_MODE=${CONF_FILES_MODE}
FILES_SUBST+=		CONF_FILES_PERMS=${CONF_FILES_PERMS:Q}
FILES_SUBST+=		SUPPORT_FILES=${SUPPORT_FILES:Q}
FILES_SUBST+=		SUPPORT_FILES_MODE=${SUPPORT_FILES_MODE}
FILES_SUBST+=		SUPPORT_FILES_PERMS=${SUPPORT_FILES_PERMS:Q}
FILES_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS:Q}
FILES_SUBST+=		RCD_SCRIPTS_MODE=${RCD_SCRIPTS_MODE}
FILES_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}
FILES_SUBST+=		RCD_SCRIPTS_EXAMPLEDIR=${RCD_SCRIPTS_EXAMPLEDIR}
FILES_SUBST+=		RCD_SCRIPTS_SHELL=${RCD_SCRIPTS_SHELL}
MESSAGE_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

# OWN_DIRS contains a list of directories for this package that should be
#       created and should attempt to be destroyed by the INSTALL/DEINSTALL
#	scripts.  MAKE_DIRS is used the same way, but the package admin
#	isn't prompted to remove the directory at post-deinstall time if it
#	isn't empty.
#
# OWN_DIRS_PERMS contains a list of "directory owner group mode" sublists
#	representing directories for this package that should be
#	created/destroyed by the INSTALL/DEINSTALL scripts.  MAKE_DIRS_PERMS
#	is used the same way but the package admin isn't prompted to remove
#	the directory at post-deinstall time if it isn't empty.
#
MAKE_DIRS?=		# empty
MAKE_DIRS_PERMS?=	# empty
OWN_DIRS?=		# empty
OWN_DIRS_PERMS?=	# empty
FILES_SUBST+=		MAKE_DIRS=${MAKE_DIRS:Q}
FILES_SUBST+=		MAKE_DIRS_PERMS=${MAKE_DIRS_PERMS:Q}
FILES_SUBST+=		OWN_DIRS=${OWN_DIRS:Q}
FILES_SUBST+=		OWN_DIRS_PERMS=${OWN_DIRS_PERMS:Q}

# PKG_CREATE_USERGROUP indicates whether the INSTALL script should
#	automatically add any needed users/groups to the system using
#	useradd/groupadd.  It is either YES or NO and defaults to YES.
#
# PKG_CONFIG indicates whether the INSTALL/DEINSTALL scripts should do
#	automatic config file and directory handling, or if it should
#	merely inform the admin of the list of required files and
#	directories needed to use the package.  It is either YES or NO
#	and defaults to YES.
#
# PKG_RCD_SCRIPTS indicates whether to automatically install rc.d scripts
#	to ${RCD_SCRIPTS_DIR}.  It is either YES or NO and defaults to
#	NO.  This variable only takes effect if ${PKG_CONFIG} == "YES".
#
# These values merely set the defaults for INSTALL/DEINSTALL scripts, but
# they may be overridden by resetting them in the environment.
#
PKG_CREATE_USERGROUP?=	YES
PKG_CONFIG?=		YES
PKG_RCD_SCRIPTS?=	NO
FILES_SUBST+=		PKG_CREATE_USERGROUP=${PKG_CREATE_USERGROUP}
FILES_SUBST+=		PKG_CONFIG=${PKG_CONFIG}
FILES_SUBST+=		PKG_RCD_SCRIPTS=${PKG_RCD_SCRIPTS}

# PKG_REGISTER_SHELLS indicates whether to automatically register shells
#	in /etc/shells.  It is either YES or NO and defaults to YES.
#
# PKG_SHELL contains the full pathname of the shell being installed.
#

PKG_REGISTER_SHELLS?=	YES
PKG_SHELL?=		# empty
FILES_SUBST+=		PKG_REGISTER_SHELLS=${PKG_REGISTER_SHELLS}
FILES_SUBST+=		PKG_SHELL=${PKG_SHELL:Q}

# Substitute for various programs used in the DEINSTALL/INSTALL scripts and
# in the rc.d scripts.
#
FILES_SUBST+=		AWK=${AWK:Q}
FILES_SUBST+=		BASENAME=${BASENAME:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		DIRNAME=${DIRNAME:Q}
FILES_SUBST+=		ECHO=${ECHO:Q}
FILES_SUBST+=		EGREP=${EGREP:Q}
FILES_SUBST+=		EXPR=${EXPR:Q}
FILES_SUBST+=		FALSE=${FALSE:Q}
FILES_SUBST+=		FIND=${FIND:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		GROUPADD=${GROUPADD:Q}
FILES_SUBST+=		GTAR=${GTAR:Q}
FILES_SUBST+=		HEAD=${HEAD:Q}
FILES_SUBST+=		ID=${ID:Q}
FILES_SUBST+=		INSTALL_INFO=${INSTALL_INFO:Q}
FILES_SUBST+=		LINKFARM=${LINKFARM:Q}
FILES_SUBST+=		LN=${LN:Q}
FILES_SUBST+=		LS=${LS:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		MV=${MV:Q}
FILES_SUBST+=		PERL5=${PERL5:Q}
FILES_SUBST+=		PKG_ADMIN=${PKG_ADMIN_CMD:Q}
FILES_SUBST+=		PKG_INFO=${PKG_INFO_CMD:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		SED=${SED:Q}
FILES_SUBST+=		SETENV=${SETENV:Q}
FILES_SUBST+=		SH=${SH:Q}
FILES_SUBST+=		SORT=${SORT:Q}
FILES_SUBST+=		SU=${SU:Q}
FILES_SUBST+=		TEST=${TEST:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}
FILES_SUBST+=		TR=${TR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST+=		USERADD=${USERADD:Q}
FILES_SUBST+=		XARGS=${XARGS:Q}

FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

INSTALL_SCRIPTS_ENV=	PKG_PREFIX=${PREFIX}

.PHONY: pre-install-script post-install-script

pre-install-script: generate-install-scripts
	${_PKG_SILENT}${_PKG_DEBUG}${SETENV} ${INSTALL_SCRIPTS_ENV}	\
		${_PKG_DEBUG_SCRIPT} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install-script:
	${_PKG_SILENT}${_PKG_DEBUG}${SETENV} ${INSTALL_SCRIPTS_ENV}	\
		${_PKG_DEBUG_SCRIPT} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.PHONY: generate-install-scripts
post-build: generate-install-scripts
generate-install-scripts:	# do nothing

.if !empty(DEINSTALL_SRC)
generate-install-scripts: ${DEINSTALL_FILE}
${DEINSTALL_FILE}: ${DEINSTALL_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} |			\
		${SED} ${FILES_SUBST_SED} > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif

.if !empty(INSTALL_SRC)
generate-install-scripts: ${INSTALL_FILE}
${INSTALL_FILE}: ${INSTALL_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} |			\
		${SED} ${FILES_SUBST_SED} > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif

# rc.d scripts are automatically generated and installed into the rc.d
# scripts example directory at the post-install step.  The following
# variables are relevent to this process:
#
# RCD_SCRIPTS			lists the basenames of the rc.d scripts
#
# RCD_SCRIPT_SRC.<script>	the source file for <script>; this will
#				be run through FILES_SUBST to generate
#				the rc.d script
#
# RCD_SCRIPTS_EXAMPLEDIR	the directory in which to install the
#				example rc.d scripts
#
# If the source rc.d script is not present, then the automatic handling
# doesn't occur.

.PHONY: generate-rcd-scripts
post-build: generate-rcd-scripts
generate-rcd-scripts:	# do nothing

.PHONY: install-rcd-scripts
post-install: install-rcd-scripts
install-rcd-scripts:	# do nothing

.for _script_ in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${_script_}?=	${FILESDIR}/${_script_}.sh
RCD_SCRIPT_WRK.${_script_}?=	${WRKDIR}/${_script_}

GENERATE_PLIST+=	${ECHO} ${RCD_SCRIPTS_EXAMPLEDIR:S|${PREFIX}/||}/${_script_};

.  if !empty(RCD_SCRIPT_SRC.${_script_})
.    if exists(${RCD_SCRIPT_SRC.${_script_}})
generate-rcd-scripts: ${RCD_SCRIPT_WRK.${_script_}}
${RCD_SCRIPT_WRK.${_script_}}: ${RCD_SCRIPT_SRC.${_script_}}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} |			\
		${SED} ${FILES_SUBST_SED} > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}

install-rcd-scripts: install-rcd-${_script_}
install-rcd-${_script_}: ${RCD_SCRIPT_WRK.${_script_}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -d ${RCD_SCRIPTS_EXAMPLEDIR} ]; then			\
		${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			-m 0755	${RCD_SCRIPTS_EXAMPLEDIR};		\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${RCD_SCRIPT_WRK.${_script_}} ]; then			\
		${INSTALL_SCRIPT} ${RCD_SCRIPT_WRK.${_script_}}		\
			${RCD_SCRIPTS_EXAMPLEDIR}/${_script_};		\
	fi
.    endif
.  endif
.endfor

.endif	# BSD_PKG_INSTALL_MK
