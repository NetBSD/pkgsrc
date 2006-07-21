# $NetBSD: Makefile,v 1.22 2006/07/21 05:06:20 rillig Exp $
#

DISTNAME=	gworkspace-0.7.1
PKGREVISION=	4
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/	\
		http://www.imago.ro/gworkspace/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/enrico/gworkspace/
COMMENT=	GNUstep Workspace manager

CONFLICTS+=	GWLib-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/gw/GW/}
USE_TOOLS+=	gs:run file:run sh:run
USE_LANGUAGES=	c objc
CONFIGURE_ARGS+=	--with-sh=${TOOLS_PATH.sh:Q}
CONFIGURE_ARGS+=	--with-file=${TOOLS_PATH.file:Q}

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
