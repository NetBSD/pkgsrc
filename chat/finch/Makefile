# $NetBSD: Makefile,v 1.32 2011/07/30 20:13:07 gls Exp $

PKGNAME=	finch-${PIDGIN_VERSION}
PKGREVISION=	1

COMMENT=	Multi-protocol Instant Messaging client console frontend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../chat/libpurple/Makefile.common"

USE_TOOLS+=	intltool msgfmt perl

PKGCONFIG_OVERRIDE+=	finch/finch.pc.in
PKGCONFIG_OVERRIDE+=	finch/libgnt/gnt.pc.in
PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in
PKGCONFIG_OVERRIDE+=	pidgin/pidgin.pc.in

CONFIGURE_ARGS+=	--enable-consoleui
CONFIGURE_ENV+=		ac_cv_path_pythonpath=

#CONFIGURE_ARGS+=	--disable-plugins

# The configure script uses an incredibly stupid way to detect if the
# ncurses header is present.  As such, it needs the exact path to the
# ncurses header it will use, so provide the path to the one in
# ${BUILDLINK_DIR}.
#
CONFIGURE_ARGS+=	--with-ncurses-headers=${BUILDLINK_DIR}/include

USE_NCURSES=		yes # force ncurses, for libpanel

BUILD_DIRS=		finch
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${MKDIR} ${WRKSRC}/libpurple/.libs
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ln -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/finch.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.libpurple+=	libpurple-${PIDGIN_VERSION}{,nb*}
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
