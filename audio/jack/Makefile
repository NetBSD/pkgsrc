# $NetBSD: Makefile,v 1.2 2006/04/19 15:25:09 joerg Exp $
#

DISTNAME=		jack-audio-connection-kit-0.100.0
PKGNAME=		jack-0.100.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://jackit.sourceforge.net/
COMMENT=		Low-latency audio server

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
