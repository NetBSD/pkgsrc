# $NetBSD: Makefile,v 1.23 2016/02/25 11:09:50 jperkin Exp $

DISTNAME=	httperf-0.9.0
PKGREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/research/linux/httperf/
COMMENT=	Popular web server benchmarking program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_TOOLS+=		gmake
CFLAGS+=		-DFD_SETSIZE=16424

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR} \
			bindir=${PREFIX}/bin

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
