# $NetBSD: Makefile,v 1.16 2004/02/17 13:15:54 dmcmahill Exp $
#

DISTNAME=	gperf-3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gperf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gperf/gperf.html
COMMENT=	GNU perfect hash function generator

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir="${PREFIX}/man"

INFO_FILES=		gperf.info

.include "../../mk/bsd.pkg.mk"
