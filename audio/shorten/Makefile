# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 22:23:34 zuntum Exp $
# FreeBSD: ports/audio/shorten/Makefile,v 1.6 2000/11/02 22:40:59 fenner Exp 
#

DISTNAME=	shorten-3.1
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/software/

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://www.softsound.com/Shorten.html
COMMENT=	lossless audio compressor

LICENSE=	no-commercial-use

MAKE_ENV+=	MKDIR="${MKDIR}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/tr156.tex ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/tr156.ps ${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
