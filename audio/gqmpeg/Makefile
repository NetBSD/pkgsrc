# $NetBSD: Makefile,v 1.51 2002/02/04 17:04:10 rxg Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp

DISTNAME=		gqmpeg-0.12.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		rxg@ms25.url.com.tw
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

BUILD_USES_MSGFMT=	yes

DEPENDS+=		mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=		vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=              xmp>=2.0.2:../../audio/xmp

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext \
			--datadir=${PREFIX}/${PKGLOCALEDIR}
.if !defined(GQMPEG_NO_JAPANESE)
CONFIGURE_ARGS+=	--enable-japanese
.endif
.if !defined(GQMPEG_NO_RUSSIAN)
CONFIGURE_ARGS+=	--enable-russian
.endif
CONFIGURE_ENV+=		GNOME_DATADIR=${PREFIX}/share

# in case gnome isn't installed, we need to create the directories
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnome/apps/Multimedia
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
