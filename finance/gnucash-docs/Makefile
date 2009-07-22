# $NetBSD: Makefile,v 1.24 2009/07/22 09:01:26 wiz Exp $

DISTNAME=		gnucash-docs-2.2.0
CATEGORIES=		finance
MASTER_SITES=		http://www.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

DEPENDS+=		yelp-[0-9]*:../../misc/yelp

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
