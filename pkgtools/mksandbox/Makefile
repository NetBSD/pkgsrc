# $NetBSD: Makefile,v 1.3 2012/09/11 23:19:35 asau Exp $

DISTNAME=	mksandbox-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/bulk.html#setting-up-a-sandbox
COMMENT=	Tool for creating sandboxes
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-extract:
	cd ${FILESDIR} && cp mksandbox mksandbox.8 ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		up
SUBST_STAGE.up=		do-configure
SUBST_FILES.up=		mksandbox mksandbox.8
SUBST_SED.up+=		-e 's,/usr/pkgsrc,${PKGSRCDIR},g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mksandbox ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/mksandbox.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
