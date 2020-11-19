# $NetBSD: Makefile,v 1.13 2020/11/19 09:35:40 schmonz Exp $
#

DISTNAME=		queue-fix-1.4
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		djberrno

SUBST_CLASSES+=		groups
SUBST_STAGE.groups=	do-configure
SUBST_FILES.groups=	queue-fix.c
SUBST_VARS.groups=	QMAIL_QMAIL_GROUP

SUBST_CLASSES+=		users
SUBST_STAGE.users=	do-configure
SUBST_FILES.users=	queue-fix.c
SUBST_VARS.users=	QMAIL_QUEUE_USER
SUBST_VARS.users+=	QMAIL_REMOTE_USER
SUBST_VARS.users+=	QMAIL_SEND_USER

BUILD_DEFS+=		QMAIL_QUEUE_USER QMAIL_REMOTE_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP

INSTALLATION_DIRS+=	share/doc/queue-fix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
