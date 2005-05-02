# $NetBSD: Makefile,v 1.11 2005/05/02 06:35:55 rh Exp $
#

DISTNAME=	gworkspace-0.7.1
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/	\
		http://www.imago.ro/gworkspace/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/enrico/gworkspace/
COMMENT=	GNUstep Workspace manager

CONFLICTS+=	GWLib-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/gw/GW/}
USE_X11=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
