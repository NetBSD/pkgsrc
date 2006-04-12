# $NetBSD: Makefile,v 1.1.1.1 2006/04/12 20:43:27 rillig Exp $
#

DISTNAME=		jack-audio-connection-kit-0.100.0
PKGNAME=		jack-0.100.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://jackit.sourceforge.net/
COMMENT=		Low-latency audio server

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

.include "../../mk/bsd.pkg.mk"
