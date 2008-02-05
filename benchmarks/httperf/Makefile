# $NetBSD: Makefile,v 1.16 2008/02/05 13:51:09 reed Exp $

DISTNAME=	httperf-0.8
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/research/linux/httperf/
COMMENT=	Popular web server benchmarking program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
