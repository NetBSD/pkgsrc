# $NetBSD: Makefile,v 1.6 2005/08/10 20:56:14 jlam Exp $
#

DISTNAME=	eet-0.9.9
CATEGORIES=	devel archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	Peter.Bex@student.kun.nl
HOMEPAGE=	http://www.enlightenment.org/pages/eet.html
COMMENT=	Library for speedy storage, retrieval, and compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
