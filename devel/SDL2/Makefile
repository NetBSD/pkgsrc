# $NetBSD: Makefile,v 1.16 2016/01/03 11:15:12 wiz Exp $

DISTNAME=	SDL2-2.0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer is a cross-platform multimedia library
LICENSE=	zlib

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	sdl2.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		configure
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

CFLAGS+=	-DPREFIX=\"${PREFIX}\"

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
