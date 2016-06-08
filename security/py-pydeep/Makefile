# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:39 wiz Exp $

DISTNAME=	pydeep-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydeep/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.github.com/kbandla/pydeep
COMMENT=	Python bindings for ssdeep
LICENSE=	modified-bsd

.include "../../security/ssdeep/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
