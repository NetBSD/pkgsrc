# $NetBSD: Makefile,v 1.96 2024/05/29 16:31:29 adam Exp $

PKGNAME=	finch-${PIDGIN_VERSION}
PKGREVISION=	5

COMMENT=	Multi-protocol console instant messaging client

.include		"../../chat/libpurple/Makefile.common"

USE_TOOLS+=	intltool msgfmt perl

CONFIGURE_ARGS+=	--enable-consoleui
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		ac_cv_path_pythonpath=

#CONFIGURE_ARGS+=	--disable-plugins

# The configure script uses an incredibly stupid way to detect if the
# ncurses header is present.  As such, it needs the exact path to the
# ncurses header it will use, so provide the path to the one in
# ${BUILDLINK_DIR}.
#
CONFIGURE_ARGS+=	--with-ncurses-headers=${BUILDLINK_DIR}/include

BUILD_DIRS=		finch

.include "options.mk"

pre-build:
	# XXX Find a cleaner way.
	${MKDIR} ${WRKSRC}/libpurple/.libs
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ln -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple

INSTALL_DIRS=		finch doc

# this was an option, but doesn't seem to be one as of 2.10.12
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"

BUILDLINK_API_DEPENDS.libpurple+=	libpurple-${PIDGIN_VERSION}{,nb*}
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libgnt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
