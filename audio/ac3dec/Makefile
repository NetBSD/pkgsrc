# $NetBSD: Makefile,v 1.3 2000/04/06 15:42:41 wiz Exp $
#

DISTNAME=	ac3dec-0.6.1
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
