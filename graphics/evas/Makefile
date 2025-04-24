# $NetBSD: Makefile,v 1.31 2025/04/24 14:14:16 wiz Exp $

COMMENT=	Enlightened Canvas Library
PKGREVISION=	5

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-font-loader-eet
CONFIGURE_ENV+=		EET_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.eet}/lib -L${BUILDLINK_PREFIX.eet}/lib -leet"

PKGCONFIG_OVERRIDE=	evas.pc.in

INSTALLATION_DIRS=	lib/evas/modules/loaders lib/evas/modules/savers \
			share/doc/evas

.include "../../mk/bsd.prefs.mk"

PLIST_SRC+=	PLIST
.if ${OPSYS} == "NetBSD"
.  if exists(/var/shm)
# /var/shm was added together with shm_open, so use this as test.
PLIST_SRC+=	PLIST.cserve
.  endif
.elif ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux"
# No shm_open on OpenBSD
.else
# Assume shm_open exists as sane default.
PLIST_SRC+=	PLIST.cserve
.endif

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	PLIST.Darwin
.endif

# Explicitly select cserve, avoids epoll/inotify.
CONFIGURE_ARGS.SunOS+=	--enable-evas-cserve
CONFIGURE_ARGS.SunOS+=	--disable-evas-cserve2

LIBS.SunOS+=	-lsocket

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/evas

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
