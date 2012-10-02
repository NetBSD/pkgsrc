# $NetBSD: Makefile,v 1.5 2012/10/02 23:48:12 asau Exp $

DISTNAME=		wavpack-4.50.1
CATEGORIES=		audio
MASTER_SITES=		http://www.wavpack.com/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.wavpack.com/
COMMENT=		Audio codec for lossless, lossy and hybrid compression
LICENSE=		modified-bsd

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	wavpack.pc.in
USE_LIBTOOL=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
