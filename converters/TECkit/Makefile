# $NetBSD: Makefile,v 1.5 2012/10/03 00:20:09 asau Exp $

DISTNAME=	TECkit_2_5_1
PKGNAME=	${DISTNAME:S/_/-/:S/_/./g}
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&cat_id=TECkit
COMMENT=	Low-level toolkit to perform encoding conversions
LICENSE=	gnu-lgpl-v2.1 OR cpl-1.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
