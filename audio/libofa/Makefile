# $NetBSD: Makefile,v 1.36 2021/12/08 16:03:15 adam Exp $
#

DISTNAME=		libofa-0.9.3
PKGREVISION=		27
CATEGORIES=		audio
MASTER_SITES=		https://www.aydogan.net/distfiles/audio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://code.google.com/archive/p/musicip-libofa/
COMMENT=		Open Fingerprint Architecture library
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libofa.pc.in

.include "../../math/fftw/buildlink3.mk"
# next two only needed for examples
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
