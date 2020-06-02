# $NetBSD: Makefile,v 1.65 2020/06/02 08:22:31 adam Exp $

DISTNAME=	audacious-4.0.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://audacious-media-player.org/
COMMENT=	Media player based on BMP and XMMS
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		intltool msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	audacious.pc.in

# XXX does not solve linking problem completely
LDFLAGS.Darwin+=	-flat_namespace -undefined suppress

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
