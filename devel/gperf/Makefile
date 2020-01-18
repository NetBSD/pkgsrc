# $NetBSD: Makefile,v 1.31 2020/01/18 23:30:28 rillig Exp $

DISTNAME=	gperf-3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gperf/gperf.html
COMMENT=	GNU perfect hash function generator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
