# $NetBSD: Makefile,v 1.79 2005/02/21 09:46:43 adam Exp $

DISTNAME=	gaim-1.1.3
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+ 2.x based multi-protocol instant messaging client

BUILD_USES_MSGFMT=	yes

CONFLICTS+=		gaim-gnome-[0-9]*

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--disable-binreloc
CONFIGURE_ARGS+=	--with-silc-includes=${BUILDLINK_PREFIX.silc-toolkit}/include/silc
CONFIGURE_ARGS+=	--with-silc-libs=${BUILDLINK_PREFIX.silc-toolkit}/lib/silc
CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-nss
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-gevolution

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
