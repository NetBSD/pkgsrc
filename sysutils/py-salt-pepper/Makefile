# $NetBSD: Makefile,v 1.5 2022/01/13 19:31:24 wiz Exp $

DISTNAME=	salt-pepper-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt-pepper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saltstack/pepper
COMMENT=	CLI front-end to a running salt-api system
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pepper pepper-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
