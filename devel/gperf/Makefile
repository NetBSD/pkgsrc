# $NetBSD: Makefile,v 1.15 2003/12/03 15:56:16 adam Exp $
#

DISTNAME=	gperf-3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gperf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gperf/gperf.html
COMMENT=	GNU perfect hash function generator

USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir="${PREFIX}/man"

INFO_FILES=		gperf.info

.include "../../mk/bsd.pkg.mk"
