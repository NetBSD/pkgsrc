# $NetBSD: Makefile,v 1.10 2001/07/02 21:42:30 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1996/11/18 13:56:53 asami Exp 
#

DISTNAME=		xmix-2.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/sound/mixers/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xmix-2.1.mixers.patch

MAINTAINER=		packages@netbsd.org
COMMENT=		Mixer for X Window System

USE_BUILDLINK_ONLY=	yes
USE_IMAKE=		yes
WRKSRC=			${WRKDIR}/xmix

pre-configure:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

pre-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
