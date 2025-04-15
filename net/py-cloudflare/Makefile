# $NetBSD: Makefile,v 1.3 2025/04/15 05:38:03 adam Exp $

DISTNAME=	cloudflare-2.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloudflare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cloudflare/python-cloudflare
COMMENT=	Python wrapper for the Cloudflare v4 API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jsonlines-[0-9]*:../../textproc/py-jsonlines
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cli4 cli4-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/cli4/cli4.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cli4-${PYVERSSUFFIX}.1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
