# $NetBSD: Makefile,v 1.3 2009/10/22 18:34:30 adam Exp $

DISTNAME=	autopano-sift-C-2.5.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hugin.sourceforge.net/
COMMENT=	SIFT Feature Detection implementation

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
