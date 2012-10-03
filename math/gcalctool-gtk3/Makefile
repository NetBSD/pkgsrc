# $NetBSD: Makefile,v 1.10.2.1 2012/10/03 12:08:37 spz Exp $
#

DISTNAME=		gcalctool-6.4.2.1
PKGREVISION=		3
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/6.4/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://live.gnome.org/Gcalctool
COMMENT=		Desktop calculator for GNOME
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake gsed intltool flex msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
