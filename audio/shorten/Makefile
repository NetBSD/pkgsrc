# $NetBSD: Makefile,v 1.3 2002/12/24 18:55:35 wiz Exp $
#

DISTNAME=	shorten-3.5.0
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shorten/source/

MAINTAINER=	collver1@attbi.com
HOMEPAGE=	http://www.etree.org/shnutils/shorten/
COMMENT=	lossless audio compressor

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.tex ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.ps ${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
