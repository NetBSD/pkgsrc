# $NetBSD: Makefile,v 1.9 2008/06/22 01:21:31 joerg Exp $
#

DISTNAME=	eet-1.0.1
CATEGORIES=	devel archivers
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
