# $NetBSD: Makefile,v 1.9 2004/06/24 23:50:54 ben Exp $
#

DISTNAME=	shorten-3.6.0
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shorten/source/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shorten/
COMMENT=	Lossless audio compressor

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.tex ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.ps ${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
