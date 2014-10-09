# $NetBSD: Makefile,v 1.5 2014/10/09 14:06:52 wiz Exp $

DISTNAME=	crypt-1.17
PKGNAME=	libtom${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://libtom.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://libtom.org/
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
