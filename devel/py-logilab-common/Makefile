# $NetBSD: Makefile,v 1.23 2022/01/05 15:41:05 wiz Exp $

DISTNAME=	logilab-common-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logilab-common/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://www.logilab.org/project/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions-[0-9]*:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Interix"
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
.endif

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} logilab-pytest logilab-pytest-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/docs/logilab-pytest.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/logilab-pytest-${PYVERSSUFFIX}.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
