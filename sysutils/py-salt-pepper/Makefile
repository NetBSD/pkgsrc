# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:22 wiz Exp $

DISTNAME=	salt-pepper-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt-pepper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saltstack/pepper
COMMENT=	CLI front-end to a running salt-api system
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pepper pepper-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
