# $NetBSD: Makefile,v 1.20 2013/10/10 14:42:22 ryoon Exp $
#

DISTNAME=		gcalctool-6.6.2
PKGREVISION=		5
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://live.gnome.org/Gcalctool
COMMENT=		Desktop calculator for GNOME
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
