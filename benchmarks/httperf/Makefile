# $NetBSD: Makefile,v 1.8 2004/11/27 18:14:24 wiz Exp $
#

DISTNAME=	httperf-0.6
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/David_Mosberger/httperf.html
COMMENT=	Popular web server benchmarking program

LICENSE=	no-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${LOCALBASE}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${LOCALBASE}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
