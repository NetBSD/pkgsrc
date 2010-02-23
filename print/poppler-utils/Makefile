# $NetBSD: Makefile,v 1.13 2010/02/23 20:13:40 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-utils-${POPPLER_VERS}

COMMENT=		PDF utilities (from poppler)
MAINTAINER=		reed@reedmedia.net

CONFLICTS+=		poppler-0.5.1 poppler-0.5.1nb1 poppler-0.5.1nb2
CONFLICTS+=		xpdf<3.02pl4nb1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't build the splash graphics backend.
CONFIGURE_ARGS+=	--disable-splash-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
# Don't compile GLib wrapper which also needs gtk2
CONFIGURE_ARGS+=	--disable-poppler-glib
# Enable build and install of the tools
CONFIGURE_ARGS+=	--enable-utils	# the default
CONFIGURE_ARGS+=	--disable-cms

BUILD_DIRS=		utils # implies INSTALL_DIRS too

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
PTHREAD_STUBLIB=	"-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lpthstub"
.else
PTHREAD_STUBLIB=	# provided by libc
.endif
MAKE_ENV+=		PTHREAD_STUBLIB=${PTHREAD_STUBLIB}

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
