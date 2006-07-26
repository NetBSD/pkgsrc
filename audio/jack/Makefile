# $NetBSD: Makefile,v 1.6 2006/07/26 18:25:43 rillig Exp $
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
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_header_readline_chardefs_h=yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
