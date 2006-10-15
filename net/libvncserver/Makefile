# $NetBSD: Makefile,v 1.1.1.1 2006/10/15 14:03:41 bouyer Exp $
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
.include "../../mk/bsd.pkg.mk"
