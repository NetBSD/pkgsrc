# $NetBSD: Makefile,v 1.7 1998/06/18 16:15:11 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1996/11/18 13:56:53 asami Exp 
#

DISTNAME=		xmix-2.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xmix-2.1.mixers.patch

MAINTAINER=		packages@netbsd.org

USE_IMAKE=		yes
WRKSRC=			${WRKDIR}/xmix

pre-configure:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

pre-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
