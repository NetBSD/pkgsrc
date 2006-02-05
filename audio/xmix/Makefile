# $NetBSD: Makefile,v 1.20 2006/02/05 23:08:17 joerg Exp $

DISTNAME=		xmix-2.1
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/sound/mixers/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xmix-2.1.mixers.patch

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Mixer for X Window System

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=			${WRKDIR}/xmix
USE_IMAKE=		yes

pre-configure:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

pre-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${PREFIX}/lib/X11/app-defaults

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
