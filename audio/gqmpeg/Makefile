# $NetBSD: Makefile,v 1.92 2006/07/13 10:13:54 wiz Exp $

DISTNAME=		gqmpeg-0.20.0
PKGREVISION=		10
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

DEPENDS+=		mpg123{,-esound,-nas}>=0.59.18:../../audio/mpg123
DEPENDS+=		vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=		xmp>=2.0.2:../../audio/xmp

USE_TOOLS+=		msgfmt
USE_DIRS+=		gnome1-1.5
USE_DIRS+=		xdg-1.2
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "options.mk"

CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GNOME_DATADIR=${PREFIX}/share

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
