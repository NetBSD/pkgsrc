# $NetBSD: Makefile,v 1.9 1999/08/22 22:59:59 kim Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.5.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.visi.com/users/mtpins/ \
		ftp://ftp.gw.com/pub/unix/news/nn/

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
