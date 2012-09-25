# $NetBSD: Makefile,v 1.4 2012/09/25 11:16:57 sbd Exp $

DISTNAME=	TECkit_2_5_1
PKGNAME=	${DISTNAME:S/_/-/:S/_/./g}
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&cat_id=TECkit
COMMENT=	Low-level toolkit to perform encoding conversions
LICENSE=	gnu-lgpl-v2.1 OR cpl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
