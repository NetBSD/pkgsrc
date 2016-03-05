# $NetBSD: Makefile,v 1.73 2016/03/05 11:28:24 jperkin Exp $

DISTNAME=	mono-tools-3.10
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/mono-tools/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Tools for use with the Mono runtime

PKGCONFIG_OVERRIDE+=	create-native-map/lib/pkgconfig/create-native-map.pc.in
PKGCONFIG_OVERRIDE+=	gendarme/framework/gendarme-framework.pc.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake msgfmt zip

MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--mandir=${PKGMANDIR}

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	post-patch
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
