# $NetBSD: Makefile,v 1.16 2024/03/03 08:11:20 adam Exp $

DISTNAME=	wavpack-5.7.0
CATEGORIES=	audio
MASTER_SITES=	https://www.wavpack.com/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.wavpack.com/
COMMENT=	Audio codec for lossless, lossy and hybrid compression
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	wavpack.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
