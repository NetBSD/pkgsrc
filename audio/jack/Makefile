# $NetBSD: Makefile,v 1.9 2006/11/29 18:48:23 xtraeme Exp $
#

DISTNAME=		jack-audio-connection-kit-0.100.0
PKGNAME=		jack-0.100.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://jackaudio.org/
COMMENT=		Low-latency audio server

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_header_readline_chardefs_h=yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

LIBS+=			${LIBOSSAUDIO}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
