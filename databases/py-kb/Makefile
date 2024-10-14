# $NetBSD: Makefile,v 1.9 2024/10/14 06:45:34 wiz Exp $

DISTNAME=	kb-manager-0.1.7
EGGNAME=	${DISTNAME:S/-manager//}
PKGNAME=	${PYPKGPREFIX}-${EGGNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kb-manager/}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/gnebbia/kb
COMMENT=	Minimalist command line knowledge base manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colored-[0-9]*:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
