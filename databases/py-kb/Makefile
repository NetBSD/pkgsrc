# $NetBSD: Makefile,v 1.6 2023/08/01 23:20:39 wiz Exp $

DISTNAME=	kb-manager-0.1.7
EGGNAME=	${DISTNAME:S/-manager//}
PKGNAME=	${PYPKGPREFIX}-${EGGNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kb-manager/}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/gnebbia/kb/
COMMENT=	Minimalist command line knowledge base manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colored-[0-9]*:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

# Not for 2.7.
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
