# $NetBSD: Makefile,v 1.63 2002/09/11 09:48:46 wiz Exp $
#

DISTNAME=		gqmpeg-0.19.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

BUILD_USES_MSGFMT=	yes
DEPENDS+=		mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=		vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=		xmp>=2.0.2:../../audio/xmp

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext \
			--datadir=${PREFIX}/${PKGLOCALEDIR}

.include "../../mk/bsd.prefs.mk"

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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
