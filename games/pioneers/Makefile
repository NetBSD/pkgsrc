# $NetBSD: Makefile,v 1.12 2008/01/18 05:06:36 tnn Exp $
#

DISTNAME=	pioneers-0.11.3
PKGREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pio/}

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://pio.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config msgfmt
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

BUILDLINK_DEPMETHOD.librsvg=	build	# generates icons

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_FILES.paths=	docs/*.6
SUBST_SED.paths=	-e s,/usr/share/,${PREFIX}/share/,

.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
