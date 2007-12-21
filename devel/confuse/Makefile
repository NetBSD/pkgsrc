# $NetBSD: Makefile,v 1.3 2007/12/21 20:32:45 joerg Exp $
#

DISTNAME=	confuse-2.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/confuse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/confuse/
COMMENT=	Configuration file parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
