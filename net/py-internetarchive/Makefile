# $NetBSD: Makefile,v 1.1 2026/09/22 17:35:09 ryoon Exp $

DISTNAME=	internetarchive-5.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/internetarchive/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jjjake/internetarchive
COMMENT=	Python interface to archive.org
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-jsonpatch>=0.4:../../textproc/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.0.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.0:../../www/py-urllib3

post-install:
.for bin in ia
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
