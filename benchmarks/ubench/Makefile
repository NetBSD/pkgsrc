# $NetBSD: Makefile,v 1.11 2019/11/03 11:55:29 rillig Exp $
#

DISTNAME=	ubench-0.32
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phystech.com/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.phystech.com/download/ubench.html
COMMENT=	The Unix Benchmark utility
LICENSE=	gnu-gpl-v2

BUILD_TARGET=		ubench
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/ubench

CFLAGS.SunOS+=	-DSunOS
CFLAGS.Linux+=	-D_POSIX_SOURCE

.include "../../mk/bsd.pkg.mk"
