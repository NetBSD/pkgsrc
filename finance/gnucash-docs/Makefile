# $NetBSD: Makefile,v 1.43 2020/01/26 17:31:10 rillig Exp $

DISTNAME=		gnucash-docs-3.4-1
# only for 3.4-1
PKGNAME=		${DISTNAME:S/-1/.0.1/}
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v3 AND gnu-fdl-v1.1

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

# only for 3.4-1
WRKSRC=			${WRKDIR}/gnucash-docs-3.4
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
