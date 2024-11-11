# $NetBSD: Makefile,v 1.35 2024/11/11 07:28:15 wiz Exp $

DISTNAME=	mako-1.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mako/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.makotemplates.org/
COMMENT=	Hyperfast and lightweight templating for the Python platform
LICENSE=	mit

WHEEL_NAME=	Mako-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.9.2:../../textproc/py-markupsafe

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mako-render mako-render-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
