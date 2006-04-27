# $NetBSD: Makefile,v 1.6 2006/04/27 03:14:19 wulf Exp $

VERSION=	0.8
DISTNAME=	gr-usrp-${VERSION}
PKGNAME=	gnuradio-usrp-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	USRP bindings for GNU Radio

PYTHON_PATCH_SCRIPTS+=	src/flexrf_debug_gui.py
PYTHON_PATCH_SCRIPTS+=	src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
