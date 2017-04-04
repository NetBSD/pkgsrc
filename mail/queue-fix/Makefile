# $NetBSD: Makefile,v 1.10 2017/04/04 07:46:14 schmonz Exp $
#

DISTNAME=		queue-fix-1.4
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

INSTALLATION_DIRS=	bin

DJB_RESTRICTED=		NO

SUBST_CLASSES+=		groups
SUBST_STAGE.groups=	do-configure
SUBST_FILES.groups=	queue-fix.c
SUBST_SED.groups=	-e 's,@QMAIL_QMAIL_GROUP@,${QMAIL_QMAIL_GROUP:Q},g'

SUBST_CLASSES+=		users
SUBST_STAGE.users=	do-configure
SUBST_FILES.users=	queue-fix.c
SUBST_SED.users+=	-e 's,@QMAIL_QUEUE_USER@,${QMAIL_QUEUE_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_REMOTE_USER@,${QMAIL_REMOTE_USER:Q},g'
SUBST_SED.users+=	-e 's,@QMAIL_SEND_USER@,${QMAIL_SEND_USER:Q},g'

BUILD_DEFS+=		QMAIL_QUEUE_USER QMAIL_REMOTE_USER QMAIL_SEND_USER
BUILD_DEFS+=		QMAIL_QMAIL_GROUP

INSTALLATION_DIRS+=	share/doc/queue-fix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
