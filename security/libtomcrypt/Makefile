# $NetBSD: Makefile,v 1.12 2024/07/27 08:27:34 wiz Exp $

DISTNAME=	crypt-1.18.2
PKGNAME=	libtom${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=libtom/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://www.libtom.net/LibTomCrypt/
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

PKGCONFIG_OVERRIDE+=	libtomcrypt.pc.in

INSTALLATION_DIRS+=	share/doc/libtomcrypt

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/crypt.pdf ${DESTDIR}${PREFIX}/share/doc/libtomcrypt

.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
