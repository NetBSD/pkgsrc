# $NetBSD: Makefile,v 1.10 2013/04/06 14:09:32 rodent Exp $
#

DISTNAME=	nspr-reference
PKGNAME=	${DISTNAME}-0.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=nspr/doc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_MOZILLA_ESR:=nspr/doc/}
COMMENT=	HTML Documentation for NSPR

NO_CONFIGURE=		YES
NO_BUILD=		YES
USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nspr/html
	cd ${WRKSRC} && pax  -s,.*/CVS.*,, -rwvpe . \
		${DESTDIR}${PREFIX}/share/doc/nspr/html

.include "../../mk/bsd.pkg.mk"
