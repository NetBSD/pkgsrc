# $NetBSD: Makefile,v 1.2 2000/01/07 04:20:49 hubertf Exp $
#

DISTNAME=	ac3dec-0.5.6
CATEGORIES=	audio
MASTER_SITES=	http://ess.engr.uvic.ca/~aholtzma/ac3/

MAINTAINER=	David Maxwell <david@fundy.ca>
HOMEPAGE=	http://ess.engr.uvic.ca/~aholtzma/ac3/

GNU_CONFIGURE=  yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/ac3dec

.include "../../mk/bsd.pkg.mk"
