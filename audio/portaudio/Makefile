# $NetBSD: Makefile,v 1.5 2005/05/22 20:07:39 jlam Exp $

DISTNAME=	portaudio_v18_1
PKGNAME=	portaudio-18.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS=		--prefix=${PREFIX}
EXTRACT_CMD_OPTS.zip=	-aqo

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
