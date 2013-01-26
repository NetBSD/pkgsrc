# $NetBSD: Makefile,v 1.48 2013/01/26 21:37:22 adam Exp $

DISTNAME=	mono-tools-2.10
PKGREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mono-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Tools for use with the Mono runtime

PKGCONFIG_OVERRIDE+=	create-native-map/lib/pkgconfig/create-native-map.pc.in
PKGCONFIG_OVERRIDE+=	gendarme/framework/gendarme-framework.pc.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake msgfmt

MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--mandir=${PKGMANDIR}

.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
