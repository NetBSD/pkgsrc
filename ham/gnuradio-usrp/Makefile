# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 23:08:33 wulf Exp $

VERSION=	0.5
DISTNAME=	gr-usrp-${VERSION}
PKGNAME=	gnuradio-usrp-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	USRP bindings for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
