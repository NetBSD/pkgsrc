# $NetBSD: Makefile,v 1.18 2006/09/24 07:27:00 wiz Exp $

DISTNAME=		gnucash-docs-2.0.0
PKGREVISION=		2
CATEGORIES=		finance
MASTER_SITES=		http://www.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

DEPENDS+=		yelp-[0-9]*:../../misc/yelp

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
