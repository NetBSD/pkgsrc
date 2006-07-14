# $NetBSD: Makefile,v 1.15 2006/07/14 15:20:44 wiz Exp $

DISTNAME=		gnucash-docs-2.0.0
CATEGORIES=		finance
MASTER_SITES=		http://www.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.libxml2=	build
BUILDLINK_DEPMETHOD.libxslt=	build

USE_DIRS+=		gnome1-1.5
USE_TOOLS+=		gmake perl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
