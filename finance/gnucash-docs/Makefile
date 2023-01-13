# $NetBSD: Makefile,v 1.57 2023/01/13 08:24:28 wiz Exp $

DISTNAME=		gnucash-docs-4.13
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program
LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1

DEPENDS+=		yelp-[0-9]*:../../misc/yelp3

USE_CMAKE=		yes
USE_TOOLS+=		bash

# CMake Error: failed to create symbolic link '.../work/gnucash-docs-4.13/share/doc/HTML/de': File exists
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
