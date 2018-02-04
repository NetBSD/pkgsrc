# $NetBSD: Makefile,v 1.7 2018/02/04 10:16:17 bsiegert Exp $

DISTNAME=	python-gflags-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gflags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-gflags
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

REPLACE_PYTHON+=	*.py
PYDISTUTILSPKG=	yes

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
