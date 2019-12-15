# $NetBSD: Makefile,v 1.4 2019/12/15 11:24:52 adam Exp $

DISTNAME=	pydeep-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kbandla/pydeep
COMMENT=	Python bindings for ssdeep
LICENSE=	modified-bsd

.include "../../security/ssdeep/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
