# $NetBSD: Makefile,v 1.11 2012/10/31 11:16:47 asau Exp $
#

DISTNAME=	confuse-2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/confuse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/confuse/
COMMENT=	Configuration file parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config msgfmt

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in
INSTALLATION_DIRS=	lib include

# the included, but generated, lexer.c includes a
# definition of a function which is then not used.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
