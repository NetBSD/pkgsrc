# $NetBSD: Makefile,v 1.2 2007/05/09 23:43:05 tnn Exp $

DISTNAME=		wavpack-4.41.0
CATEGORIES=		audio
MASTER_SITES=		http://www.wavpack.com/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.wavpack.com/
COMMENT=		Audio codec for lossless, lossy and hybrid compression

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	wavpack.pc.in
USE_LIBTOOL=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
