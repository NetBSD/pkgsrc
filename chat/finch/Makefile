# $NetBSD: Makefile,v 1.1.1.1 2007/07/28 12:13:33 gdt Exp $
#

PKGNAME=	finch-${VERSION}

COMMENT=	Multi-protocol Instant Messaging client console frontend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../chat/libpurple/Makefile.common"

PKGCONFIG_OVERRIDE+=	finch/libgnt/gnt.pc.in
PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in
PKGCONFIG_OVERRIDE+=	pidgin/pidgin.pc.in

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--enable-consoleui

CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+=	--disable-nss
#CONFIGURE_ARGS+=	--disable-plugins

USE_NCURSES=		yes # force ncurses, for libpanel

BUILD_DIRS=finch

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ${LN} -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple/.

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR:Q}${PREFIX:Q}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/finch.1 ${DESTDIR:Q}${PREFIX:Q}/man/man1

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
