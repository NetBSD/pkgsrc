# $NetBSD: Makefile,v 1.5 2022/01/10 20:42:38 wiz Exp $

DISTNAME=	pydeep-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kbandla/pydeep
COMMENT=	Python bindings for ssdeep
LICENSE=	modified-bsd

.include "../../security/ssdeep/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
