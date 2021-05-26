# $NetBSD: Makefile,v 1.1 2021/05/26 18:49:20 brook Exp $

GITHUB_PROJECT=	minimap2
GITHUB_TAG=	refs/tags/v2.18
DISTNAME=	v2.18
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/minimap2
COMMENT=	Minimap2 python binding
LICENSE=	mit

WRKSRC=		${WRKDIR}/minimap2-2.18
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/examples/minimap2

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/examples/minimap2
	${INSTALL_DATA} ${WRKSRC}/cookbook.md ${DESTDIR}${PREFIX}/share/examples/minimap2

BUILDLINK_DEPENDS.py-cython+=	build
BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.29.23
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
