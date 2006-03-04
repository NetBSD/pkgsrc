# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=	httperf-0.6
PKGREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/David_Mosberger/httperf.html
COMMENT=	Popular web server benchmarking program

LICENSE=	no-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${PREFIX}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man ${PREFIX}/man/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
