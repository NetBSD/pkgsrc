# $NetBSD: Makefile,v 1.14 2006/12/07 06:27:30 cjs Exp $

DISTNAME=	httperf-0.8
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/research/linux/httperf/
COMMENT=	Popular web server benchmarking program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httperf ${PREFIX}/bin/httperf
	${INSTALL_MAN} ${WRKSRC}/httperf.man \
	    ${PREFIX}/${PKGMANDIR}/man1/httperf.1

.include "../../mk/bsd.pkg.mk"
