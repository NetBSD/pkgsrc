# $NetBSD: Makefile,v 1.8 2018/05/25 02:08:36 bsiegert Exp $

DISTNAME=	python-gflags-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
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
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
