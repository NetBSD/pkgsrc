# $NetBSD: Makefile,v 1.4 2014/01/09 15:34:02 jperkin Exp $

DISTNAME=	lrzip-0.616
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://ck.kolivas.org/apps/lrzip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tm@core.io
HOMEPAGE=	http://ck.kolivas.org/apps/lrzip/
COMMENT=	Long Range ZIP or Lzma RZIP
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run pkg-config pod2man
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lrzip.pc.in

REPLACE_BASH+=	lrztar

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
