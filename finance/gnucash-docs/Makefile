# $NetBSD: Makefile,v 1.52 2021/12/20 00:43:31 wiz Exp $

DISTNAME=		gnucash-docs-4.9
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

USE_CMAKE=		yes
USE_TOOLS+=		bash

.include "../../mk/bsd.pkg.mk"
