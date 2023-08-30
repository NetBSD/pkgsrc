# $NetBSD: Makefile,v 1.3 2023/08/30 21:46:33 js Exp $

DISTNAME=	ijson-3.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
GITHUB_PROJECT=	ijson
MASTER_SITES=	${MASTER_SITE_GITHUB:=ICRAR/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/ICRAR/ijson
COMMENT=	Iterative JSON parser with standard Python iterator interfaces
LICENSE=	modified-bsd

.include "../../devel/yajl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
