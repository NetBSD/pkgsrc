# $NetBSD: Makefile,v 1.12 2021/01/19 10:17:43 adam Exp $

DISTNAME=	wavpack-5.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wavpack.com/
COMMENT=	Audio codec for lossless, lossy and hybrid compression
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	wavpack.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
