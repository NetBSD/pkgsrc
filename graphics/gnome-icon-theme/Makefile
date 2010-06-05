# $NetBSD: Makefile,v 1.67 2010/06/05 10:16:37 wiz Exp $
#

DISTNAME=		gnome-icon-theme-2.30.3
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config
# otherwise it creates lots of lib/locale dirs, even though it doesn't
# need them (!)
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

post-install:
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 16 -h 16 -o ${DESTDIR}${PREFIX}/share/icons/gnome/16x16/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 22 -h 22 -o ${DESTDIR}${PREFIX}/share/icons/gnome/22x22/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 24 -h 24 -o ${DESTDIR}${PREFIX}/share/icons/gnome/24x24/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 32 -h 32 -o ${DESTDIR}${PREFIX}/share/icons/gnome/32x32/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 48 -h 48 -o ${DESTDIR}${PREFIX}/share/icons/gnome/48x48/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 256 -h 256 -o ${DESTDIR}${PREFIX}/share/icons/gnome/256x256/places/start-here.png

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILD_DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
.include "../../mk/bsd.pkg.mk"
