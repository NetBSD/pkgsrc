# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:07 tv Exp $

DISTNAME=	liteamp-0.2.4.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_PERL5=		build
USE_LIBTOOL=		yes

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
