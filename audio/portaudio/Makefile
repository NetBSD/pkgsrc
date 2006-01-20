# $NetBSD: Makefile,v 1.10 2006/01/20 23:41:29 jlam Exp $

DISTNAME=	portaudio_v18_1
PKGNAME=	portaudio-18.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

EXTRACT_OPTS_ZIP=	-aqo

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
