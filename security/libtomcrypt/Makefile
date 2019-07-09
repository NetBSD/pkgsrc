# $NetBSD: Makefile,v 1.8 2019/07/09 11:20:58 nia Exp $

DISTNAME=	crypt-1.18.2
PKGNAME=	libtom${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=libtom/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/libtom/libtomcrypt
COMMENT=	Tom St Denis's cryptographic library
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile.shared

# This disables funrolling the loops.
MAKE_FLAGS+=	IGNORE_SPEED=1
MAKE_FLAGS+=	EXTRALIBS="-ltommath"

CPPFLAGS+=	-DUSE_LTM -DLTM_DESC

.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
