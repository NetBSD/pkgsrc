# $NetBSD: Makefile,v 1.8 2016/07/09 13:03:45 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.10

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
