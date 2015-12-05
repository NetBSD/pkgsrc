# $NetBSD: Makefile,v 1.7 2015/12/05 21:25:41 adam Exp $

DISTNAME=	${VERS}
PKGNAME=	transifex-client-${VERS}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/transifex/transifex-client/archive/
DIST_SUBDIR=	transifex-client

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/transifex-client
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

VERS=		0.10
WRKSRC=		${WRKDIR}/transifex-client-${VERS}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.10

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
