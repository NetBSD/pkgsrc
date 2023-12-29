# $NetBSD: Makefile,v 1.15 2023/12/29 01:08:16 zafer Exp $

DISTNAME=	wavpack-5.6.0
CATEGORIES=	audio
MASTER_SITES=	https://www.wavpack.com/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wavpack.com/
COMMENT=	Audio codec for lossless, lossy and hybrid compression
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	wavpack.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
