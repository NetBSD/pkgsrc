# $NetBSD: Makefile,v 1.6 2004/12/14 06:21:50 minskim Exp $
#

DISTNAME=		gmpc-0.11.2
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/gmpc/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://qballcow.nl/?name=gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_DIRS+=		xdg-1.1

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
