# $NetBSD: Makefile,v 1.80 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=		gqmpeg-0.20.0
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

BUILD_USES_MSGFMT=	yes
DEPENDS+=		mpg123{,-esound,-nas}>=0.59.18:../../audio/mpg123
DEPENDS+=		vorbis-tools>=1.0.0.6:../../audio/vorbis-tools
DEPENDS+=		xmp>=2.0.2:../../audio/xmp

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

.include "../../mk/bsd.prefs.mk"

.if !defined(GQMPEG_NO_JAPANESE)
CONFIGURE_ARGS+=	--enable-japanese
.endif
.if !defined(GQMPEG_NO_RUSSIAN)
CONFIGURE_ARGS+=	--enable-russian
.endif
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GNOME_DATADIR=${PREFIX}/share

# in case gnome isn't installed, we need to create the directories
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnome/apps/Multimedia
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
