# $NetBSD: Makefile,v 1.17 2006/08/10 15:28:40 jmmv Exp $

DISTNAME=		gnucash-docs-2.0.0
PKGREVISION=		1
CATEGORIES=		finance
MASTER_SITES=		http://www.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
