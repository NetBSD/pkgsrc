# $NetBSD: Makefile,v 1.17 2005/03/24 21:12:51 wiz Exp $

DISTNAME=		xmix-2.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/sound/mixers/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xmix-2.1.mixers.patch

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Mixer for X Window System

WRKSRC=			${WRKDIR}/xmix
USE_IMAKE=		yes

pre-configure:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

pre-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
