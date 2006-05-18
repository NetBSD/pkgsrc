# $NetBSD: Makefile,v 1.3 2006/05/18 20:29:58 wiz Exp $
#

DISTNAME=		jack-audio-connection-kit-0.100.0
PKGNAME=		jack-0.100.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://jackit.sourceforge.net/
COMMENT=		Low-latency audio server

BROKEN_IN=		pkgsrc-2006Q1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
