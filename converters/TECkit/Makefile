# $NetBSD: Makefile,v 1.6 2015/06/14 10:01:41 markd Exp $

DISTNAME=	TECkit_2.5.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	converters
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&cat_id=TECkit
COMMENT=	Low-level toolkit to perform encoding conversions
LICENSE=	gnu-lgpl-v2.1 OR cpl-1.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake

PKGCONFIG_OVERRIDE=	teckit.pc.in

pre-configure:
		(cd ${WRKSRC}; ./autogen.sh)

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
