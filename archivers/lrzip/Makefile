# $NetBSD: Makefile,v 1.6 2017/04/05 17:34:38 adam Exp $

DISTNAME=	lrzip-0.631
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tm@core.io
HOMEPAGE=	http://ck.kolivas.org/apps/lrzip/
COMMENT=	Long Range ZIP or Lzma RZIP
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run pkg-config pod2man
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	lrzip.pc.in

REPLACE_BASH+=	lrztar

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
