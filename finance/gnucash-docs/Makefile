# $NetBSD: Makefile,v 1.40 2018/10/17 15:32:53 bsiegert Exp $

DISTNAME=		gnucash-docs-3.3
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v3 AND gnu-fdl-v1.1

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
