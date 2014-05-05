# $NetBSD: Makefile,v 1.3 2014/05/05 00:48:07 ryoon Exp $

DISTNAME=		gnome-calculator-3.10.2
PKGREVISION=		1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-calculator/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://wiki.gnome.org/Apps/Calculator
COMMENT=		Desktop calculator for GNOME
LICENSE=		gnu-gpl-v2

DEPENDS+=		gnome-icon-theme-symbolic-[0-9]*:../../graphics/gnome-icon-theme-symbolic
BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

CONFLICTS+=		gcalctool-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/vala018/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
