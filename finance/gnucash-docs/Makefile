# $NetBSD: Makefile,v 1.71 2025/09/29 20:26:53 wiz Exp $

DISTNAME=		gnucash-docs-5.13
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

USE_TOOLS+=		bash

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
