# $NetBSD: Makefile,v 1.11 2015/08/16 01:05:09 mef Exp $

DISTNAME=	netperf-2.7.0
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.netperf.org/netperf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
INFO_FILES=		yes

CFLAGS.IRIX+=		-DIRIX

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
.if !exists(/usr/include/malloc.h)
post-wrapper:
	${ECHO} "#include <stdlib.h>" > ${BUILDLINK_DIR}/include/malloc.h
.endif

.include "../../mk/bsd.pkg.mk"
