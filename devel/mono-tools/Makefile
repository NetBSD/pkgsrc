# $NetBSD: Makefile,v 1.10 2009/03/25 22:37:12 he Exp $

DISTNAME=	mono-tools-2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mono-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Tools for use with the Mono runtime

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	create-native-map/lib/pkgconfig/create-native-map.pc.in
PKGCONFIG_OVERRIDE+=	gendarme/framework/gendarme-framework.pc.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--mandir=${PKGMANDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
