# $NetBSD: Makefile,v 1.14 2020/11/01 00:20:05 markd Exp $

DISTNAME=	freerdp-2.1.2
PKGNAME=	${DISTNAME:S/freerdp-/freerdp2-/1}
CATEGORIES=	net
MASTER_SITES=	https://pub.freerdp.com/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freerdp.com/
COMMENT=	Free implementation of the Remote Desktop Protocol (major version 2)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DWITH_SERVER=ON
CMAKE_ARGS+=	-DWITH_CHANNELS=ON
CMAKE_ARGS+=	-DWITH_JPEG=ON
CMAKE_ARGS+=	-DWITH_WAYLAND=OFF # XXX needs epoll
CMAKE_ARGS+=	-DWITH_GSTREAMER_1_0=OFF

CMAKE_ARGS+=	-DAVCODEC_LIBRARY=${PREFIX}/lib/ffmpeg4/libavcodec.so

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CMAKE_ARGS+=	-DWITH_OSS=ON
LDFLAGS+=	${LIBOSSAUDIO}
.else
CMAKE_ARGS+=	-DWITH_OSS=OFF
.endif

# backtrace
LDFLAGS.NetBSD+=	-lexecinfo

PKGCONFIG_OVERRIDE+=	freerdp.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7

post-install:
.for page in freerdp-shadow-cli.1 winpr-hash.1 winpr-makecert.1 xfreerdp.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/${page} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${page} || ${TRUE}
.endfor
	${MV} ${DESTDIR}${PREFIX}/share/man/man7/wlog.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/wlog.7 || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/xfreerdp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xfreerdp2.1 || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/xfreerdp \
		${DESTDIR}${PREFIX}/bin/xfreerdp2 || ${TRUE}

.include "options.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
