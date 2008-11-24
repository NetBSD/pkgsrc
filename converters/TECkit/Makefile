# $NetBSD: Makefile,v 1.1.1.1 2008/11/24 02:09:31 minskim Exp $

DISTNAME=	TECkit_2_5_1
PKGNAME=	${DISTNAME:S/_/-/:S/_/./g}
CATEGORIES=	converters
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&cat_id=TECkit
COMMENT=	Low-level toolkit to perform encoding conversions

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
