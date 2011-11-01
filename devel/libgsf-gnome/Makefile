# $NetBSD: Makefile,v 1.15 2011/11/01 06:00:59 sbd Exp $
#

DISTNAME=	libgsf-1.14.21
PKGNAME=	${DISTNAME:S/libgsf/libgsf-gnome/}
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgsf/1.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 structured file library (GNOME support)
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

CONFLICTS+=	libgsf<1.14.15nb1

DISTINFO_FILE=	${.CURDIR}/../libgsf/distinfo
PATCHDIR=	${.CURDIR}/../libgsf/patches
BUILD_DIRS=	gsf-gnome
INSTALLATION_DIRS=	lib/pkgconfig
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	libgsf-gnome-1.pc.in

CONFIGURE_ARGS+=	--without-python

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
