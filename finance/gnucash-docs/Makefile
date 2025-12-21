# $NetBSD: Makefile,v 1.72 2025/12/21 18:28:59 wiz Exp $

DISTNAME=		gnucash-docs-5.14
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
