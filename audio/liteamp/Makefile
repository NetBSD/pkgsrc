# $NetBSD: Makefile,v 1.52 2012/10/02 17:10:33 tron Exp $

DISTNAME=	liteamp-0.2.4.2
PKGREVISION=	31
CATEGORIES=	audio
MASTER_SITES=	http://kldp.net/frs/download.php/1153/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CPPFLAGS+=		-UGNOME_DISABLE_DEPRECATED
CPPFLAGS+=		-UGTK_DISABLE_DEPRECATED
LDFLAGS+=		${BUILDLINK_LDADD.oss}

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
