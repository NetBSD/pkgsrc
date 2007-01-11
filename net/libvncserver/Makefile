# $NetBSD: Makefile,v 1.2 2007/01/11 11:51:20 joerg Exp $
#

DISTNAME=		LibVNCServer-0.8.2
PKGNAME=		libVNCServer-0.8.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=		pierrick@bs-network.net
HOMEPAGE=		http://libvncserver.sourceforge.net/
COMMENT=		Easy API to write one's own vnc server

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
