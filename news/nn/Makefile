# $NetBSD: Makefile,v 1.5 1998/06/22 13:00:14 agc Exp $
# $FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/old/beta/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/nn.old/beta/

MAINTAINER=     tron@netbsd.org

DEPENDS=	nntpclnt-1.6.1:../../news/nntpclnt

post-extract:
	@${MV} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@${SED} -e 's#@@PREFIX@@#${PREFIX}#; \
	  s#@@BINOWN@@#${BINOWN}#; \
	  s#@@BINGRP@@#${BINGRP}#' \
	  <${FILESDIR}/s-netbsd.h >${WRKSRC}/conf/s-netbsd.h

.include <../../mk/bsd.pkg.mk>
