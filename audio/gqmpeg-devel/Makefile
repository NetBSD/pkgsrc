# $NetBSD: Makefile,v 1.55 2018/11/12 03:51:41 ryoon Exp $

DISTNAME=		gqmpeg-0.91.1
PKGREVISION=		34
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123
LICENSE=		gnu-gpl-v2

DEPENDS+=		mpg123{,-esound,-nas}>=0.59.18:../../audio/mpg123
DEPENDS+=		vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=		xmp>=2.0.2:../../audio/xmp

USE_TOOLS+=		msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GNOME_DATADIR=${PREFIX}/share

REPLACE_SH=		plugin/gqmpeg-shoutcast-plugin.sh

MAKE_ENV+=		builddir=.

LIBS.SunOS+=		-lm -lX11
LDFLAGS.DragonFly=	-lm -lX11

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
