# $NetBSD: Makefile,v 1.1 2016/05/03 14:53:05 fhajny Exp $

DISTNAME=	pyfasthash-0.6.2
PKGNAME=	${DISTNAME:S/pyfast/${PYPKGPREFIX}-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=flier/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/flier/pyfasthash/
COMMENT=	Python Non-cryptographic Hash Library
LICENSE=	apache-2.0

GITHUB_PROJECT=	pyfasthash

USE_LANGUAGES=	c c++

EGG_NAME=	${DISTNAME:S/fast//}

.include "../../devel/py-boost/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
