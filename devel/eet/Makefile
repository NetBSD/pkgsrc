# $NetBSD: Makefile,v 1.16 2009/12/16 21:28:26 joerg Exp $
#

DISTNAME=	eet-1.2.3
CATEGORIES=	devel archivers
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
