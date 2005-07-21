# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:46 wiz Exp $
#

DISTNAME=	eet-0.9.9
CATEGORIES=	devel archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	Peter.Bex@student.kun.nl
HOMEPAGE=	http://www.enlightenment.org/pages/eet.html
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
