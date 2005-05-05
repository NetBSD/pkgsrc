# $NetBSD: Makefile,v 1.1.1.1 2005/05/05 05:49:28 rh Exp $
#

DISTNAME=		Cenon-3.67
CATEGORIES=		graphics cad gnustep
MASTER_SITES=		http://www.vhf-group.com/vhfInterservice/download/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cenon.info/
COMMENT=		Vector graphics / CAD / DTP program

WRKSRC=			${WRKDIR}/Cenon
USE_X11=		yes
NO_CONFIGURE=		yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
