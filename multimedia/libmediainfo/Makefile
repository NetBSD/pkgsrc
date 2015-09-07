# $NetBSD: Makefile,v 1.5 2015/09/07 01:02:00 dsainty Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		libmediainfo-${MIVER}

COMMENT=		MediaInfoLib, support library for MediaInfo program
LICENSE=		zlib

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_DIRS+=	MediaInfoLib/Project/GNU/Library

REPLACE_SH=		MediaInfoLib/Project/GNU/Library/libmediainfo-config.in

PKGCONFIG_OVERRIDE+=	MediaInfoLib/Project/GNU/Library/libmediainfo.pc.in

.include "../../mk/bsd.prefs.mk"
# Enable shared library
.if empty(_OPSYS_SHLIB_TYPE:Mnone)
CONFIGURE_ARGS+=	--enable-shared
.endif

INSTALLATION_DIRS+=	bin lib/pkgconfig

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS:Q} && autoreconf -i

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${CONFIGURE_DIRS:Q}/libmediainfo-config \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${CONFIGURE_DIRS:Q}/libmediainfo.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libzen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
