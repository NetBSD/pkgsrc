# $NetBSD: Makefile,v 1.2 1998/05/19 22:26:39 tron Exp $
# $FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/old/beta/

MAINTAINER=     tron@netbsd.org

MAN1=		nn.1 nncheck.1 nngoback.1 nngrab.1  nngrep.1 nnpost.1 \
		nntidy.1 nnacct.1 nnadmin.1 nnstats.1 nnusage.1
MAN8=		nnmaster.8 nnspew.8

post-extract:
	@${MV} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@${SED} -e 's#@@PREFIX@@#${PREFIX}#; \
	  s#@@BINOWN@@#${BINOWN}#; \
	  s#@@BINGRP@@#${BINGRP}#' \
	  <${FILESDIR}/s-netbsd.h >${WRKSRC}/conf/s-netbsd.h

post-build:
	(cd ${WRKSRC}/inews; ${MAKE} all)

pre-install:
	(cd ${WRKSRC}/inews; ${MAKE} install)

post-install:
	@${ECHO} "Put your NNTP host into \"${PREFIX}/etc/nntp_server\" file."

.include <../../mk/bsd.pkg.mk>
