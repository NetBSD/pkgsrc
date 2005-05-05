# $NetBSD: Makefile,v 1.2 2005/05/05 05:59:17 rh Exp $
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Cenon
.for doc in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/Cenon
.endfor

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
