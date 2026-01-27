# $NetBSD: Makefile,v 1.99 2026/01/27 08:39:33 wiz Exp $

DISTNAME=	pioneers-15.6
PKGREVISION=	23
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pio.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config msgfmt intltool
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_FILES.paths=	docs/*.6
SUBST_SED.paths=	-e s,/usr/share/,${PREFIX}/share/,

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
