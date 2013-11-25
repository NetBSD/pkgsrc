# $NetBSD: Makefile,v 1.29 2013/11/25 12:00:47 wiz Exp $
#

SQUEAK_VERSION=	4.10.2.2614

DISTNAME=	Squeak-${SQUEAK_VERSION}-src
PKGNAME=	squeak-vm-${SQUEAK_VERSION:C/-/./}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://squeakvm.org/unix/release/ \
		http://ftp.squeak.org/3.10/unix-linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeakvm.org/unix/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows
LICENSE=	2-clause-bsd

DIST_SUBDIR=		squeak
CHECK_PORTABILITY_SKIP=	unix/config/configure	# not used anymore

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS=	gzip

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	../unix
#CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=TRUE	# debug
CMAKE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}
CMAKE_ARGS+=	-DVM_HOST=${MACHINE_GNU_PLATFORM:Q} -DVM_VERSION=${SQUEAK_VERSION}
CMAKE_ARGS+=	-DDEVOSSAUDIO=${DEVOSSAUDIO}

LDFLAGS.SunOS+=	-liconv -lsocket -lnsl -lm

.include "../../mk/bsd.prefs.mk"

.if $(OPSYS) == "NetBSD"
# UUID routines are in libc:
BUILDLINK_TRANSFORM+=	rm:-luuid
.endif

PLIST_SUBST=	SQUEAK_VERSION=${SQUEAK_VERSION}

.include "options.mk"

PLIST_VARS+=	oss

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.if $(OSS_TYPE) != "none"
PLIST.oss=	yes
CMAKE_ARGS+=	-DLIBOSSAUDIO=${LIBOSSAUDIO:S/-l//}
.endif
.include "../../mk/bsd.pkg.mk"
