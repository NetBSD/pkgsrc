# $NetBSD: Makefile,v 1.5 2005/02/09 20:22:08 wiz Exp $

DISTNAME=		gnucash-docs-1.8.5
CATEGORIES=		finance
MASTER_SITES=		http://www.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

BUILD_DEPENDS=			docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.libxml2=	build
BUILDLINK_DEPMETHOD.libxslt=	build

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
