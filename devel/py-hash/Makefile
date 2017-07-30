# $NetBSD: Makefile,v 1.5 2017/07/30 22:32:16 wiz Exp $

DISTNAME=	pyfasthash-0.6.2
PKGNAME=	${DISTNAME:S/pyfast/${PYPKGPREFIX}-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=flier/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/flier/pyfasthash/
COMMENT=	Python Non-cryptographic Hash Library
LICENSE=	apache-2.0

GITHUB_PROJECT=	pyfasthash

USE_LANGUAGES=	c c++

EGG_NAME=	${DISTNAME:S/fast//}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
CPPFLAGS+=	-DHASH_LITTLE_ENDIAN=1 -DHASH_BIG_ENDIAN=0
.else
CPPFLAGS+=	-DHASH_LITTLE_ENDIAN=0 -DHASH_BIG_ENDIAN=1
.endif

.include "../../devel/py-boost/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
