# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:06 tv Exp $
#

DISTNAME=		gmpc-0.10.2
PKGREVISION=		3
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
