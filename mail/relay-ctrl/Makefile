# $NetBSD: Makefile,v 1.1.1.1 2007/02/28 14:12:40 schmonz Exp $
#

DISTNAME=	relay-ctrl-3.1.1
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://untroubled.org/relay-ctrl/
COMMENT=	Allows relaying via POP/IMAP-before-SMTP

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 ${DOCDIR}
OWN_DIRS_PERMS+=	${RELAY_CTRL_DIR} ${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${RELAY_CTRL_DIR}/allow ${ROOT_USER} ${ROOT_GROUP} 777
MESSAGE_SUBST+=		RELAY_CTRL_DIR=${RELAY_CTRL_DIR:Q} DOCDIR=${DOCDIR:Q}
BUILD_DEFS+=		RELAY_CTRL_DIR

ADDON_SCRIPTS=		dovecot-settcpremoteip ifrelayclient

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${ADDON_SCRIPTS}
SUBST_SED.paths=	-e 's,@ECHO@,${ECHO},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP},g'
SUBST_SED.paths+=	-e 's,@SED@,${SED},g'
SUBST_SED.paths+=	-e 's,@SETENV@,${SETENV},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	do-configure

post-extract:
	for f in ${ADDON_SCRIPTS}; do					\
		${CP} ${FILESDIR}/$$f.sh ${WRKSRC}/$$f;			\
	done

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	./installer;							\
	./instcheck
	for f in ANNOUNCEMENT COPYING NEWS README TODO packet.html; do	\
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${DOCDIR};	\
	done
	for f in ${ADDON_SCRIPTS}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${PREFIX}/bin;	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
