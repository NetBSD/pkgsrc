# $NetBSD: Makefile,v 1.2 2000/11/02 03:43:08 toshii Exp $
#

DISTNAME=	httperf-0.6
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.hpl.hp.com/personal/David_Mosberger/httperf.html

LICENSE=	no-commercial-use

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${LOCALBASE}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${LOCALBASE}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
