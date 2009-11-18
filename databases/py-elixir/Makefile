# $NetBSD: Makefile,v 1.1.1.1 2009/11/18 14:57:42 he Exp $
#

DISTNAME=	Elixir-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/E/Elixir/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://elixir.ematia.de/trac/wiki
COMMENT=	Elixir is a declarative layer on top of the SQLAlchemy library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=   user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy/
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2/
DEPENDS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*:../../security/py-amkCrypto

# Python stuff
PYTHON_VERSIONS_ACCEPTED= 26 25

PYDISTUTILSPKG=		yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
