# $NetBSD: Makefile,v 1.33 2016/04/09 05:55:46 wiz Exp $

DISTNAME=		gnucash-docs-2.6.12
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v3 AND gnu-fdl-v1.1

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
