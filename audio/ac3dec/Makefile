# $NetBSD: Makefile,v 1.5 2001/02/16 13:30:32 wiz Exp $
#

DISTNAME=	ac3dec-0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://gusnet.cx/aaron/codecs/tarballs/

MAINTAINER=	David Maxwell <david@fundy.ca>
HOMEPAGE=	http://ess.engr.uvic.ca/~aholtzma/ac3/
COMMENT=	ac3 audio (as used on DVDs) decoding tools

GNU_CONFIGURE=  yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/ac3dec

.include "../../mk/bsd.pkg.mk"
