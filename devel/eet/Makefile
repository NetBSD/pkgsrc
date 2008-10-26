# $NetBSD: Makefile,v 1.11 2008/10/26 04:48:22 minskim Exp $
#

DISTNAME=	eet-1.1.0
CATEGORIES=	devel archivers
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFIGURE_ENV+=	OPENSSL_CFLAGS=-I${BUILDLINK_PREFIX.openssl}/include \
		OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
