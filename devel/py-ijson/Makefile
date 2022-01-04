# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:10 wiz Exp $

DISTNAME=	ijson-3.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
GITHUB_PROJECT=	ijson
MASTER_SITES=	${MASTER_SITE_GITHUB:=ICRAR/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/ICRAR/ijson
COMMENT=	Iterative JSON parser with standard Python iterator interfaces
LICENSE=	modified-bsd

.include "../../devel/yajl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
