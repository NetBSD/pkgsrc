# $NetBSD: Makefile,v 1.13 2005/07/21 16:29:44 wiz Exp $

DISTNAME=	liteamp-0.2.4.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CPPFLAGS+=		-UGNOME_DISABLE_DEPRECATED
CPPFLAGS+=		-UGTK_DISABLE_DEPRECATED

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
