# $NetBSD: Makefile,v 1.2 2015/04/28 01:27:40 mef Exp $

DISTNAME=	libcec-2.2.0-repack
PKGNAME=	${DISTNAME:S/-repack//}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pulse-Eight/}
GITHUB_PROJECT=	libcec
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcec.pulse-eight.com/
COMMENT=	USB CEC Adapter communication Library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/libcec-libcec-2.2.0-repack
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake autoconf automake autoreconf
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/lib/libcec.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.if !empty(MACHINE_ARCH:M*arm*)
CONFIGURE_ARGS+=	--with-rpi-include-path=${PREFIX}/include
CONFIGURE_ARGS+=	--with-rpi-lib-path=${PREFIX}/lib
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
