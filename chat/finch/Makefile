# $NetBSD: Makefile,v 1.10 2008/02/02 21:43:27 gdt Exp $
#

PKGNAME=	finch-${PIDGIN_VERSION}
PKGREVISION=	1

COMMENT=	Multi-protocol Instant Messaging client console frontend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../chat/libpurple/Makefile.common"

USE_TOOLS+=	msgfmt

PKGCONFIG_OVERRIDE+=	finch/finch.pc.in
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

CONFIGURE_ARGS+=	--with-ncurses-headers=${PREFIX}/include/ncursesw
CONFIGURE_ENV+=		ac_cv_lib_ncursesw_initscr=yes
CONFIGURE_ENV+=		ac_cv_lib_panelw_update_panels=yes

USE_NCURSES=		yes # force ncurses, for libpanel

BUILD_DIRS=finch

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ln -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple/.

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR:Q}${PREFIX:Q}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/finch.1 ${DESTDIR:Q}${PREFIX:Q}/man/man1

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
