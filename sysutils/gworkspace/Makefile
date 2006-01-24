# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:35 wiz Exp $
#

DISTNAME=	gworkspace-0.7.1
PKGREVISION=	1
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/	\
		http://www.imago.ro/gworkspace/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/enrico/gworkspace/
COMMENT=	GNUstep Workspace manager

BROKEN_IN=	pkgsrc-2005Q4

CONFLICTS+=	GWLib-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/gw/GW/}
USE_TOOLS+=	gs:run

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
