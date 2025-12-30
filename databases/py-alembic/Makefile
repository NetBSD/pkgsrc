# $NetBSD: Makefile,v 1.45 2025/12/30 12:57:02 adam Exp $

DISTNAME=	alembic-1.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alembic/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://alembic.sqlalchemy.org/
COMMENT=	Database migration tool for SQLAlchemy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} alembic alembic-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
