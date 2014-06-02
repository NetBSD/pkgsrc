# $NetBSD: Makefile,v 1.1 2014/06/02 00:00:15 rodent Exp $

DISTNAME=	pydeep-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/p/pydeep/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.github.com/kbandla/pydeep
COMMENT=	Python bindings for ssdeep
LICENSE=	modified-bsd

.include "../../security/ssdeep/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
