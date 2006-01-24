# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:10 wiz Exp $
#

DISTNAME=		Cenon-3.67
PKGREVISION=		1
CATEGORIES=		graphics cad gnustep
MASTER_SITES=		http://www.vhf-group.com/vhfInterservice/download/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cenon.info/
COMMENT=		Vector graphics / CAD / DTP program

WRKSRC=			${WRKDIR}/Cenon
NO_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Cenon
.for doc in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/Cenon
.endfor

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
