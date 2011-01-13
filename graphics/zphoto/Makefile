# $NetBSD: Makefile,v 1.16 2011/01/13 13:38:24 wiz Exp $
#

DISTNAME=	zphoto-1.2
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://0xcc.net/zphoto/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://0xcc.net/zphoto/
COMMENT=	Flash-based photo album generator
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv:Q}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
