# $NetBSD: Makefile,v 1.85 2023/11/08 13:19:20 wiz Exp $
#

DISTNAME=	pioneers-15.6
PKGREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pio.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config msgfmt intltool itstool
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

BUILDLINK_DEPMETHOD.librsvg=	build	# generates icons

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_FILES.paths=	docs/*.6
SUBST_SED.paths=	-e s,/usr/share/,${PREFIX}/share/,

.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
