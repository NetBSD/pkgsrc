# $NetBSD: Makefile,v 1.1.1.1 2004/02/18 01:28:29 minskim Exp $

DISTNAME=	liteamp-0.2.4.1
CATEGORIES=	audio
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

DEPENDS+=	xdg-dirs>=1.0:../../misc/xdg-dirs
DEPENDS+=	gnome2-dirs>=1.2nb1:../../misc/gnome2-dirs

USE_BUILDLINK3=		yes
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
.include "../../mk/bsd.pkg.mk"
