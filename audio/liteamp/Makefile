# $NetBSD: Makefile,v 1.18 2006/01/24 07:31:54 wiz Exp $

DISTNAME=	liteamp-0.2.4.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://kldp.net/frs/download.php/1153/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CPPFLAGS+=		-UGNOME_DISABLE_DEPRECATED
CPPFLAGS+=		-UGTK_DISABLE_DEPRECATED

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
