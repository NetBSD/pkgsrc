# $NetBSD: Makefile,v 1.1 2021/01/28 21:17:37 maya Exp $

GITHUB_PROJECT=	tubes
GITHUB_TAG=	v0.2.0
DISTNAME=	v0.2.0
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=twisted/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/tubes/
COMMENT=	Data-processing and flow-control engine for event-driven programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-characteristic-[0-9]*:../../devel/py-characteristic
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

WRKSRC=		${WRKDIR}/tubes-0.2.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
