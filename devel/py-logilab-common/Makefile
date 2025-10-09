# $NetBSD: Makefile,v 1.25 2025/10/09 08:07:27 wiz Exp $

DISTNAME=	logilab_common-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logilab-common/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://forge.extranet.logilab.fr/open-source/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions-[0-9]*:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} logilab-pytest logilab-pytest-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/docs/logilab-pytest.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/logilab-pytest-${PYVERSSUFFIX}.1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
