# $NetBSD: Makefile,v 1.11 2020/11/19 09:35:42 schmonz Exp $
#

DISTNAME=		relay-ctrl-3.2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/relay-ctrl/
COMMENT=		Allows relaying via POP/IMAP-before-SMTP

DJB_MAKE_TARGETS=	NO

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 ${DOCDIR}
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}
OWN_DIRS_PERMS+=	${RELAY_CTRL_DIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${RELAY_CTRL_DIR}/allow ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 777
MESSAGE_SUBST+=		RELAY_CTRL_DIR=${RELAY_CTRL_DIR:Q} DOCDIR=${DOCDIR:Q}
BUILD_DEFS+=		RELAY_CTRL_DIR

ADDON_SCRIPTS=		dovecot-settcpremoteip ifrelayclient

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${ADDON_SCRIPTS}
SUBST_VARS.paths=	ECHO
SUBST_VARS.paths+=	GREP
SUBST_VARS.paths+=	SED
SUBST_VARS.paths+=	SETENV
SUBST_VARS.paths+=	SH
SUBST_STAGE.paths=	do-configure

CFLAGS.SunOS+=		-DSOL_TCP=SOL_SOCKET
LDFLAGS.SunOS+=		-lsocket

post-extract:
	for f in ${ADDON_SCRIPTS}; do					\
		${CP} ${FILESDIR}/$$f.sh ${WRKSRC}/$$f;			\
	done

post-install:
	${RUN}cd ${WRKSRC};						\
	for f in ANNOUNCEMENT COPYING NEWS README TODO packet.html; do	\
		${INSTALL_DATA} ${WRKSRC}/$${f}				\
			${DESTDIR}${PREFIX}/${DOCDIR};			\
	done
	for f in ${ADDON_SCRIPTS}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${f}			\
			${DESTDIR}${PREFIX}/bin;			\
	done

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
