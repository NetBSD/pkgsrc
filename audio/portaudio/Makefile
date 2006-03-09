# $NetBSD: Makefile,v 1.13 2006/03/09 21:04:41 jlam Exp $

DISTNAME=	portaudio_v18_1
PKGNAME=	portaudio-18.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
