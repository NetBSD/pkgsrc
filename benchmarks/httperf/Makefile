# $NetBSD: Makefile,v 1.3 2001/02/16 13:37:52 wiz Exp $
#

DISTNAME=	httperf-0.6
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.hpl.hp.com/personal/David_Mosberger/httperf.html
COMMENT=	Popular web server benchmarking program

LICENSE=	no-commercial-use

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${LOCALBASE}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${LOCALBASE}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
