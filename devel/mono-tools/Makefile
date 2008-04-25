# $NetBSD: Makefile,v 1.2 2008/04/25 08:18:01 kefren Exp $

DISTNAME=	mono-tools-1.9
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/mono-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Tools for use with the Mono runtime

.include "../../lang/mono/Makefile.common"

PKGCONFIG_OVERRIDE+=	create-native-map/lib/pkgconfig/create-native-map.pc.in
PKGCONFIG_OVERRIDE+=	gendarme/framework/gendarme-framework.pc.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

MAKE_JOBS_SAFE=		no

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
