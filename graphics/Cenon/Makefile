# $NetBSD: Makefile,v 1.11 2007/09/21 13:03:46 wiz Exp $
#

DISTNAME=		Cenon-3.67
PKGREVISION=		4
CATEGORIES=		graphics cad gnustep
MASTER_SITES=		http://www.vhf-group.com/vhfInterservice/download/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cenon.info/
COMMENT=		Vector graphics / CAD / DTP program

USE_LANGUAGES=		objc

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
