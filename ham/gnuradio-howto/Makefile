# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 23:06:30 wulf Exp $

VERSION=	0.3
DISTNAME=	gr-howto-write-a-block-${VERSION}
PKGNAME=	gnuradio-howto-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	Documentation about GNU Radio signal processing blocks

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
