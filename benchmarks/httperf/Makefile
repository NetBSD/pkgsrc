# $NetBSD: Makefile,v 1.1.1.1 2000/03/16 22:53:28 thorpej Exp $
#

DISTNAME=	httperf-0.6
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.hpl.hp.com/personal/Davis_Mosberger/httperf.html

LICENSE=	no-commercial-use

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${LOCALBASE}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${LOCALBASE}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
