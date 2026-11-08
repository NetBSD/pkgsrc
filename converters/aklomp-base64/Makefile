# $NetBSD: Makefile,v 1.3 2026/11/08 15:45:04 wiz Exp $

DISTNAME=	base64-0.5.3
PKGNAME=	aklomp-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=aklomp/}
GITHUB_PROJECT=	base64
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aklomp/base64/
COMMENT=	Fast Base64 stream encoder/decoder in C99, with SIMD acceleration
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} base64 aklomp-base64

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
