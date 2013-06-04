# $NetBSD: Makefile,v 1.13 2013/06/04 22:16:16 tron Exp $

PKGNAME=	evas-${EVAS_VERSION}
PKGREVISION=	2
COMMENT=	Enlightened Canvas Library

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-font-loader-eet
CONFIGURE_ENV+=		EET_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.eet}/lib -L${BUILDLINK_PREFIX.eet}/lib -leet"

PKGCONFIG_OVERRIDE=	evas.pc.in

INSTALLATION_DIRS=	lib/evas/modules/loaders lib/evas/modules/savers \
			share/doc/evas

.include "../../mk/bsd.prefs.mk"

PLIST_SRC+=	PLIST
.if ${OPSYS} != "NetBSD" && ${OPSYS} != "OpenBSD" && ${OPSYS} != "MirBSD"
PLIST_SRC+=	PLIST.cserve
.endif

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
