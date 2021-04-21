# $NetBSD: Makefile,v 1.77 2021/04/21 11:42:00 adam Exp $
#

DISTNAME=	zphoto-1.2
PKGREVISION=	67
CATEGORIES=	graphics
MASTER_SITES=	http://0xcc.net/zphoto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/zphoto/
COMMENT=	Flash-based photo album generator
LICENSE=	gnu-lgpl-v2.1

.include "options.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
