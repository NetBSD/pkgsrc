# $NetBSD: Makefile,v 1.4 2013/12/24 03:26:19 taca Exp $
#

DISTNAME=	${VERS}
PKGNAME=	transifex-client-${VERS}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/transifex/transifex-client/archive/
DIST_SUBDIR=	transifex-client

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/transifex-client
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

FETCH_USING=    wget
VERS=		0.10
WRKSRC=		${WRKDIR}/transifex-client-${VERS}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
