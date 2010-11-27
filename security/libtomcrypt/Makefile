# $NetBSD: Makefile,v 1.1.1.1 2010/11/27 06:11:57 agc Exp $

DISTNAME=	crypt-1.17
PKGNAME=	libtom${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://libtom.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://libtom.org/
COMMENT=	Tom St Denis's cryptographic library
LICENSE=	public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	makefile.unix
MAKE_ENV+=	CFLAGS_OPTS="-DUSE_LTM -DLTM_DESC"
BUILD_TARGET=	default

AUTO_MKDIRS=	yes

.include "../../math/ltm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
