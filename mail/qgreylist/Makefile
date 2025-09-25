# $NetBSD: Makefile,v 1.28 2025/09/25 16:42:31 schmonz Exp $

DISTNAME=		qgreylist-0.3
PKGREVISION=		13
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20170701214830/https://jonatkins.com/page/software/qgreylist/
COMMENT=		Simple greylisting for qmail
LICENSE=		mit

DEPENDS+=		qmail>=1.03nb8:../../mail/qmail

WRKSRC=			${WRKDIR}/qgreylist

USE_TOOLS+=		perl:run
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/greylist ${QMAIL_DAEMON_USER} ${REAL_ROOT_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/whitelist ${QMAIL_DAEMON_USER} ${REAL_ROOT_GROUP} 0755
NO_BUILD=		yes

BUILD_DEFS+=		QMAIL_DAEMON_USER

REPLACE_PERL=		greylist

PKG_SYSCONFSUBDIR=	qmail

SUBST_CLASSES+=		qmaildirs
SUBST_STAGE.qmaildirs=	pre-configure
SUBST_FILES.qmaildirs=	greylist README.pkgsrc
SUBST_SED.qmaildirs=	-e 's|/var/qmail/greylist|${PKG_SYSCONFDIR}/greylist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail/whitelist|${PKG_SYSCONFDIR}/whitelist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_VARS.qmaildirs=	PREFIX RCD_SCRIPTS_DIR

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}
BUILD_DEFS+=		QMAILDIR

post-extract:
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/greylist ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
