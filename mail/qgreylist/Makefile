# $NetBSD: Makefile,v 1.23 2019/08/11 13:21:40 wiz Exp $

DISTNAME=		qgreylist-0.3
PKGREVISION=		9
CATEGORIES=		mail
#MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://www.jonatkins.com/page/software/qgreylist
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
SUBST_STAGE.qmaildirs=	do-configure
SUBST_FILES.qmaildirs=	greylist
SUBST_SED.qmaildirs=	-e 's|/var/qmail/greylist|${PKG_SYSCONFDIR}/greylist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail/whitelist|${PKG_SYSCONFDIR}/whitelist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin share/doc/qgreylist
BUILD_DEFS+=		QMAILDIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/greylist ${DESTDIR}${PREFIX}/bin/qgreylist
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/qgreylist

.include "../../mk/bsd.pkg.mk"
