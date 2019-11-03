# $NetBSD: Makefile,v 1.14 2019/11/03 11:55:29 rillig Exp $

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

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.else
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500 -D__EXTENSIONS__
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
.if !exists(/usr/include/malloc.h)
post-wrapper:
	${ECHO} "#include <stdlib.h>" > ${BUILDLINK_DIR}/include/malloc.h
.endif

.include "../../mk/bsd.pkg.mk"
