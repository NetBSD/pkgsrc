# $NetBSD: Makefile,v 1.7 2023/08/06 07:33:40 adam Exp $

DISTNAME=	kb-manager-0.1.7
EGGNAME=	${DISTNAME:S/-manager//}
PKGNAME=	${PYPKGPREFIX}-${EGGNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kb-manager/}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/gnebbia/kb
COMMENT=	Minimalist command line knowledge base manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colored-[0-9]*:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # py-colored

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
