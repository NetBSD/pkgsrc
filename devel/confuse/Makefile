# $NetBSD: Makefile,v 1.2 2007/03/15 18:34:58 joerg Exp $
#

DISTNAME=	confuse-2.5
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/confuse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/confuse/
COMMENT=	Configuration file parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.pkg.mk"
