# $NetBSD: Makefile,v 1.7 2016/01/09 03:10:45 chuck Exp $

DISTNAME=	TECkit_2.5.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	converters
#
# scripts.sil.org is using ViewVC to dynamically generate a new .tar.gz.
# each .tar.gz has a new gzip timestamp, so its different each download.
# this makes it impossible to match checksum in distinfo, so we pull it
# from a static file on MASTER_SITE_BACKUP instead.
#
#MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/
MASTER_SITES=	${MASTER_SITE_BACKUP}

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
