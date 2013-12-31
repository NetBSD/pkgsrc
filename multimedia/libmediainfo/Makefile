# $NetBSD: Makefile,v 1.2 2013/12/31 23:21:08 ryoon Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		${DISTNAME:S/mediainfo_/libmediainfo-/S/_AllInclusive//}

COMMENT=		MediaInfoLib, support library for MediaInfo program
LICENSE=		zlib

USE_TOOLS+=		autoconf automake bash:run gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIG_SHELL=		bash
CONFIGURE_DIRS+=	MediaInfoLib/Project/GNU/Library

REPLACE_SH=		MediaInfoLib/Project/GNU/Library/libmediainfo-config.in

PKGCONFIG_OVERRIDE+=	MediaInfoLib/Project/GNU/Library/libmediainfo.pc.in

# Enable shared library
.if empty(SHLIB_TYPE:Mnone)
CONFIGURE_ARGS+=	--enable-shared
.endif

INSTALLATION_DIRS+=	bin lib/pkgconfig

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && autoreconf -i

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${CONFIGURE_DIRS}/libmediainfo-config \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${CONFIGURE_DIRS}/libmediainfo.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libzen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
