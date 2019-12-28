# $NetBSD: Makefile,v 1.10 2019/12/28 20:00:01 adam Exp $

DISTNAME=	wavpack-5.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wavpack.com/
COMMENT=	Audio codec for lossless, lossy and hybrid compression
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	wavpack.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
