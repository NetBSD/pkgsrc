# $NetBSD: bsd.pkg.install.mk,v 1.4 2001/11/21 16:10:03 jlam Exp $
#
# This Makefile fragment is included by package Makefiles to use the common
# INSTALL/DEINSTALL scripts.  To use this Makefile fragment, simply:
#
# (1) Set the variables to customize the install scripts to the package, and
# (2) Include this Makefile fragment in the package Makefile.
#
# NOTE: This file must be included _before_ bsd.pkg.mk.

.if !defined(BSD_PKG_INSTALL_MK)
BSD_PKG_INSTALL_MK=	1

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
DEINSTALL_EXTRA_TMPL?=	# empty
DEINSTALL_TMPL?=	${.CURDIR}/../../mk/install/deinstall
INSTALL_TMPL?=		${.CURDIR}/../../mk/install/install
INSTALL_EXTRA_TMPL?=	# empty
_FOOTER_TMPL?=		${.CURDIR}/../../mk/install/footer

# DEINSTALL_TEMPLATES and INSTALL_TEMPLATES are the default list of source
#	files that are concatenated to form the DEINSTALL/INSTALL scripts.
#
DEINSTALL_TEMPLATES=	${_HEADER_TMPL}
DEINSTALL_TEMPLATES+=	${DEINSTALL_EXTRA_TMPL}
DEINSTALL_TEMPLATES+=	${DEINSTALL_TMPL}
DEINSTALL_TEMPLATES+=	${_FOOTER_TMPL}
INSTALL_TEMPLATES=	${_HEADER_TMPL}
INSTALL_TEMPLATES+=	${INSTALL_TMPL}
INSTALL_TEMPLATES+=	${INSTALL_EXTRA_TMPL}
INSTALL_TEMPLATES+=	${_FOOTER_TMPL}

# These are the list of source files that are concatenated to form the
# INSTALL/DEINSTALL scripts.
#
DEINSTALL_SRC?=		${DEINSTALL_TEMPLATES}
INSTALL_SRC?=		${INSTALL_TEMPLATES}

FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		LOCALBASE=${LOCALBASE}
FILES_SUBST+=		X11BASE=${X11BASE}
FILES_SUBST+=		CONFDIR=${CONFDIR}

# PKG_USER and PKG_GROUP are the user and group that need to be created
#	before this package is installed.
#
# PKG_USERID and PKG_GROUPID are the numeric IDs used in creating the user
#	and group.  If they're blank, then the default values chosen by the
#	system is used.
#
# PKG_USER_DESCR is the description of the user to add to the system.  It
#	defaults to "foo user" for package "foo".
#
# PKG_USER_HOME is the home directory of the user to add to the system.  It
#	defaults to "/".
#
# PKG_USER_SHELL is the login shell for the user.  For system security
#	purposes, it defaults to "${NOLOGIN}".
#
PKG_USER?=		# empty
PKG_USERID?=		# empty
PKG_USER_DESCR?=	${PKGBASE} user
PKG_USER_HOME?=		/
PKG_USER_SHELL?=	${NOLOGIN}
PKG_GROUP?=		# empty
PKG_GROUPID?=		# empty
FILES_SUBST+=		PKG_USER=${PKG_USER}
FILES_SUBST+=		PKG_USERID=${PKG_USERID}
FILES_SUBST+=		PKG_USER_DESCR=${PKG_USER_DESCR:Q}
FILES_SUBST+=		PKG_USER_HOME=${PKG_USER_HOME}
FILES_SUBST+=		PKG_USER_SHELL=${PKG_USER_SHELL}
FILES_SUBST+=		PKG_GROUP=${PKG_GROUP}
FILES_SUBST+=		PKG_GROUPID=${PKG_GROUPID}

.if !empty(PKG_USER)
USE_USERADD=		YES
.endif
.if !empty(PKG_GROUP)
USE_USERGROUP=		YES
.endif

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
# RCD_SCRIPTS works lists the basenames of the rc.d scripts.  It's assumed that
#	they live in ${PREFIX}/etc/rc.d, and the scripts will be copied into
#	${RCD_SCRIPTS_DIR} with ${RCD_SCRIPTS_MODE} permissions.
#
CONF_FILES?=		# empty
CONF_FILES_MODE?=	0644
CONF_FILES_PERMS?=	# empty
SUPPORT_FILES?=		# empty
SUPPORT_FILES_MODE?=	0644
SUPPORT_FILES_PERMS?=	# empty
RCD_SCRIPTS?=		# empty
RCD_SCRIPTS_MODE?=	0755
RCD_SCRIPTS_DIR?=	/etc/rc.d
FILES_SUBST+=		CONF_FILES=${CONF_FILES:Q}
FILES_SUBST+=		CONF_FILES_MODE=${CONF_FILES_MODE}
FILES_SUBST+=		CONF_FILES_PERMS=${CONF_FILES_PERMS:Q}
FILES_SUBST+=		SUPPORT_FILES=${SUPPORT_FILES:Q}
FILES_SUBST+=		SUPPORT_FILES_MODE=${SUPPORT_FILES_MODE}
FILES_SUBST+=		SUPPORT_FILES_PERMS=${SUPPORT_FILES_PERMS:Q}
FILES_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS:Q}
FILES_SUBST+=		RCD_SCRIPTS_MODE=${RCD_SCRIPTS_MODE}
FILES_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

# OWN_DIRS contains a list of directories for this package that should be
#       created and should attempt to be destroyed by the INSTALL/DEINSTALL
#	scripts.  MAKE_DIRS is used the same way, but the package admin
#	isn't prompted to remove the directory at post-deinstall time if it
#	isn't empty.  For convenience, ${CONFDIR} and ${RCD_SCRIPTS_DIR} are
#	automatically added to MAKE_DIRS.
#
# OWN_DIRS_PERMS contains a list of "directory owner group mode" sublists
#	representing directories for this package that should be
#	created/destroyed by the INSTALL/DEINSTALL scripts.  MAKE_DIRS_PERMS
#	is used the same way but the package admin isn't prompted to remove
#	the directory at post-deinstall time if it isn't empty.
#
MAKE_DIRS?=		# empty
MAKE_DIRS_PERMS?=	# empty
_MAKE_DIRS=		${CONFDIR} ${RCD_SCRIPTS_DIR} ${MAKE_DIRS}
OWN_DIRS?=		# empty
OWN_DIRS_PERMS?=	# empty
FILES_SUBST+=		MAKE_DIRS=${_MAKE_DIRS:Q}
FILES_SUBST+=		MAKE_DIRS_PERMS=${MAKE_DIRS_PERMS:Q}
FILES_SUBST+=		OWN_DIRS=${OWN_DIRS:Q}
FILES_SUBST+=		OWN_DIRS_PERMS=${OWN_DIRS_PERMS:Q}

# Substitute for various programs used in the DEINSTALL/INSTALL scripts.
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
FILES_SUBST+=		FALSE=${FALSE:Q}
FILES_SUBST+=		GROUPADD=${GROUPADD:Q}
FILES_SUBST+=		ID=${ID:Q}
FILES_SUBST+=		LN=${LN:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		MV=${MV:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		SED=${SED:Q}
FILES_SUBST+=		SH=${SH:Q}
FILES_SUBST+=		SORT=${SORT:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}
FILES_SUBST+=		TR=${TR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST+=		USERADD=${USERADD:Q}

FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install: install-scripts

install-scripts:
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${DEINSTALL_SRC} |		\
		${SED} ${FILES_SUBST_SED} > ${DEINSTALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${DEINSTALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${INSTALL_SRC} |		\
		${SED} ${FILES_SUBST_SED} > ${INSTALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${INSTALL_FILE}

.endif	# BSD_PKG_INSTALL_MK
