# $NetBSD: Makefile,v 1.5 2022/09/28 18:58:01 leot Exp $

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

# Not for 2.7. 3.7 would need py-attr that is currently not packaged
PYTHON_VERSIONS_INCOMPATIBLE=	27 37

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
