# $NetBSD: Makefile,v 1.17 2004/11/22 21:14:29 wiz Exp $
#

DISTNAME=	gperf-3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gperf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gperf/gperf.html
COMMENT=	GNU perfect hash function generator

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir="${PREFIX}/man"

INFO_FILES=		gperf.info

.include "../../mk/bsd.pkg.mk"
