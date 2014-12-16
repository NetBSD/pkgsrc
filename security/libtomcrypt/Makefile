# $NetBSD: Makefile,v 1.6 2014/12/16 02:58:20 mef Exp $

DISTNAME=	crypt-1.17
PKGNAME=	libtom${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://libtom.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/libtom/libtomcrypt
COMMENT=	Tom St Denis's cryptographic library
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile.shared
MAKE_ENV+=	CFLAGS_OPTS="-DUSE_LTM -DLTM_DESC"
BUILD_TARGET=	default

AUTO_MKDIRS=	yes

.include "../../math/ltm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
