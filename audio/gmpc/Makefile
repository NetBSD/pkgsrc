# $NetBSD: Makefile,v 1.3 2004/05/08 15:40:53 grant Exp $
#

DISTNAME=		gmpc-0.10.2
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/gmpc/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://qballcow.nl/?s=13
COMMENT=		GNOME client for the Music Player Daemon

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_DIRS+=		xdg-1.1

.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
