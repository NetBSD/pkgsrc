# $NetBSD: djbware.mk,v 1.1 2005/03/23 00:50:06 schmonz Exp $
#
# Makefile fragment for packages with djb-style build machinery
#
# Common functions provided:
# * a boilerplate RESTRICTED clause
# * typical defaults for BUILD_TARGET and INSTALL_TARGET
# * typical values for conf-* files
#
# TODO:
# * set RESTRICTED automatically iff patches or other mods are applied
# * on recent glibc, subst.mk inline errno defn into #include <errno.h>
#

.if !defined(DJBWARE_MK)
DJBWARE_MK=		# defined

DJB_RESTRICTED?=	YES
DJB_BUILD_TARGETS?=	# empty
DJB_INSTALL_TARGETS?=	# empty
DJB_CONFIG_DIR?=	${WRKSRC}
DJB_CONFIG_PREFIX?=	${PREFIX}
DJB_CONFIG_HOME?=	conf-home
DJB_CONFIG_CMDS?=	${DO_NADA}
BGWARE_INSTALLER?=	NO

.if !empty(DJB_RESTRICTED:M[yY][eE][sS])
RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif

BUILD_TARGET?=		it ${DJB_BUILD_TARGETS}
INSTALL_TARGET?=	setup check ${DJB_INSTALL_TARGETS}

.if !target(do-configure)
do-configure:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${DJB_CONFIG_DIR};		\
	for i in conf-*; do ${CP} $${i} $${i}.orig_dist; done;		\
	[ -f ${DJB_CONFIG_HOME} ] && \
		${ECHO} ${DJB_CONFIG_PREFIX} > ${DJB_CONFIG_HOME};	\
	[ -f conf-cc ] && \
		${ECHO} ${CC:Q} ${CFLAGS:Q} > conf-cc;			\
	[ -f conf-ld ] && \
		${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > conf-ld;		\
	[ -f conf-bin ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/bin > conf-bin;		\
	[ -f conf-man ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/man > conf-man;		\
	[ -f conf-qmail ] && \
		${ECHO} ${QMAILDIR} > conf-qmail;			\
	${DJB_CONFIG_CMDS}
.endif

.if !empty(BGWARE_INSTALLER:M[yY][eE][sS])
. if !target(do-install)
do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	./installer;							\
	./instcheck
. endif
.endif

.endif	# DJBWARE_MK
