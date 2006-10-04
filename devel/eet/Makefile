# $NetBSD: Makefile,v 1.7 2006/10/04 21:35:58 wiz Exp $
#

DISTNAME=	eet-0.9.9
CATEGORIES=	devel archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	Peter.Bex@student.kun.nl
HOMEPAGE=	http://www.enlightenment.org/Libraries/Eet/
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
