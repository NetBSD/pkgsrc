# $NetBSD: Makefile,v 1.8 2014/05/15 14:41:51 adam Exp $

DISTNAME=	imlib-1.9.15
PKGNAME=	imlib-gtk-1.9.15
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/imlib/1.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nl.rasterman.com/imlib.html
COMMENT=	Image manipulation library for X11 (gtk bits)

CONFLICTS=	imlib<=1.9.15nb8

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DISTINFO_FILE=		${.CURDIR}/../imlib/distinfo
PATCHDIR=		${.CURDIR}/../imlib/patches
INSTALL_DIRS=		gdk_imlib utils

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	imlib.pc.in
UNLIMIT_RESOURCES=	datasize

CPPFLAGS+=		-DENABLE_NLS
CONFIGURE_ENV+=		ac_cv_path_CONVERT_PROG="${LOCALBASE}/bin/convert"
CONFIGURE_ENV+=		X_LDFLAGS=${X_LDFLAGS:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# breaks kde3 kuickshow if shm and other than XAA acceleration
CONFIGURE_ARGS+=	--disable-shm

PKG_SYSCONFSUBDIR=	imlib

# The following ensures that `imlib-config --libs' includes the correct
# linker flags for linking the X11 libs.
#
X_LDFLAGS=		${X11_LDFLAGS}

.include "../../mk/bsd.prefs.mk"
.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${X11PREFIX:Q}/include
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
