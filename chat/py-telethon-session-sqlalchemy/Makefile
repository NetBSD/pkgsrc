# $NetBSD: Makefile,v 1.1 2020/11/18 23:23:30 js Exp $

DISTNAME=	telethon-session-sqlalchemy-0.2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/telethon-session-sqlalchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tulir/telethon-session-sqlalchemy
COMMENT=	SQLAlchemy backend for Telethon session storage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-telethon-[0-9]*:../../chat/py-telethon
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2<2:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
