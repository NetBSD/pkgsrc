# $NetBSD: Makefile,v 1.7 1999/08/18 09:08:10 agc Exp $
# $FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/old/beta/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/nn.old/beta/

MAINTAINER=     tron@netbsd.org

BUILD_DEFS+=	USE_INN

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INN) && ${USE_INN} == YES
DEPENDS=	inn-2.2:../inn
.else
DEPENDS=	nntpclnt-1.6.1:../nntpclnt
.endif

post-extract:
	@${MV} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@${SED} -e 's#@@PREFIX@@#${PREFIX}#; \
	  s#@@BINOWN@@#${BINOWN}#; \
	  s#@@BINGRP@@#${BINGRP}#' \
	  <${FILESDIR}/s-netbsd.h >${WRKSRC}/conf/s-netbsd.h

.include "../../mk/bsd.pkg.mk"
