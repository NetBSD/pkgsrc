# $NetBSD: Makefile,v 1.5 2013/12/14 08:59:54 obache Exp $
#

DISTNAME=	Elixir-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/E/Elixir/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://elixir.ematia.de/trac/wiki
COMMENT=	Elixir is a declarative layer on top of the SQLAlchemy library
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.4.0:../../databases/py-sqlalchemy/
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2/
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
