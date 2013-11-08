# $NetBSD: Makefile,v 1.2 2013/11/08 21:14:01 joerg Exp $

DISTNAME=	lrzip-0.616
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

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
