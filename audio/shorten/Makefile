# $NetBSD: Makefile,v 1.6 2003/07/21 16:30:45 martti Exp $
#

DISTNAME=	shorten-3.5.1
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shorten/source/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.etree.org/shnutils/shorten/
COMMENT=	Lossless audio compressor

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.tex ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.ps ${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
