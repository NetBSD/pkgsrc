# $NetBSD: Makefile,v 1.35.2.1 2012/10/03 12:07:47 spz Exp $
#

DISTNAME=	pioneers-0.11.3
PKGREVISION=	20
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pio.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
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
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
