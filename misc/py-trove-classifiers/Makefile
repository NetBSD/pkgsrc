# $NetBSD: Makefile,v 1.40 2025/06/03 11:50:42 markd Exp $

DISTNAME=	trove_classifiers-2025.5.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trove-classifiers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/trove-classifiers
COMMENT=	Canonical source for classifiers on PyPI (pypi.org)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-calver-[0-9]*:../../devel/py-calver
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} trove-classifiers trove-classifiers-${PYVERSSUFFIX} || ${TRUE}

# as of 2025.5.9.12
# 3 failed, 15 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
