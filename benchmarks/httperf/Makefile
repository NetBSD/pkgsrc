# $NetBSD: Makefile,v 1.5 2003/09/19 18:06:34 wiz Exp $
#

DISTNAME=	httperf-0.6
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/David_Mosberger/httperf.html
COMMENT=	Popular web server benchmarking program

LICENSE=	no-commercial-use

USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${LOCALBASE}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${LOCALBASE}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
