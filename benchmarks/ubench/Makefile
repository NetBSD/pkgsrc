# $NetBSD: Makefile,v 1.1.1.1 2005/09/03 05:57:45 xtraeme Exp $
#

DISTNAME=	ubench-0.32
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phystech.com/ftp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.phystech.com/ftp/
COMMENT=	The Unix Benchmark utility

BUILD_TARGET=	ubench

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},"

.include "../../mk/bsd.pkg.mk"
