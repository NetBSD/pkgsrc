# $NetBSD: Makefile,v 1.9 2012/09/11 22:37:13 asau Exp $

DISTNAME=	netperf-2.4.5
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.netperf.org/netperf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

GNU_CONFIGURE=		yes
INFO_FILES=		yes

CFLAGS.IRIX+=		-DIRIX

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
