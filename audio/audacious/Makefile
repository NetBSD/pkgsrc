# $NetBSD: Makefile,v 1.42 2016/02/20 11:28:26 jperkin Exp $

DISTNAME=	audacious-3.5.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://audacious-media-player.org/
COMMENT=	Media player based on BMP and XMMS
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
# requires libguess which is not available any more
CONFIGURE_ARGS+=	--disable-chardet
PKGCONFIG_OVERRIDE+=	audacious.pc.in

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

.include "../../mk/bsd.prefs.mk"
# XXX does not solve linking problem completely
.if ${OPSYS} == "Darwin"
LDFLAGS+=	-flat_namespace -undefined suppress
.endif

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
