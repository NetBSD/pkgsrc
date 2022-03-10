# $NetBSD: Makefile,v 1.10 2022/03/10 15:05:05 ryoon Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		libmediainfo-${MIVER}

COMMENT=		MediaInfoLib, support library for MediaInfo program
LICENSE=		2-clause-bsd

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_DIRS+=	MediaInfoLib/Project/GNU/Library

REPLACE_SH=		MediaInfoLib/Project/GNU/Library/libmediainfo-config.in

PKGCONFIG_OVERRIDE+=	MediaInfoLib/Project/GNU/Library/libmediainfo.pc.in

LIBTOOL_OVERRIDE+=	${CONFIGURE_DIRS}/libtool

.include "../../mk/bsd.prefs.mk"
# Enable shared library
.if empty(SHLIB_TYPE:Mnone)
CONFIGURE_ARGS+=	--enable-shared
.endif

INSTALLATION_DIRS+=	bin lib/pkgconfig

# ../../../Source/ThirdParty/base64/base64.h: In function 'std::string Base64::encode(const string&)':
# ../../../Source/ThirdParty/base64/base64.h:53:41: error: array subscript has type 'char'
#      sResult.append(1, sBase64Table[cCode]);
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

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
