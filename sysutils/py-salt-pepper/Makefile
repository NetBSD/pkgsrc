# $NetBSD: Makefile,v 1.6 2024/04/30 13:56:53 wiz Exp $

DISTNAME=	salt-pepper-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt-pepper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saltstack/pepper
COMMENT=	CLI front-end to a running salt-api system
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	salt-[0-9]*:../../sysutils/salt

USE_LANGUAGES=	c # for tests

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pepper pepper-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
