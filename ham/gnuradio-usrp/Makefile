# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:18 wiz Exp $

VERSION=	0.6
DISTNAME=	gr-usrp-${VERSION}
PKGNAME=	gnuradio-usrp-${VERSION}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	USRP bindings for GNU Radio

PYTHON_PATCH_SCRIPTS+= src/flexrf_debug_gui.py	
PYTHON_PATCTH_SCRIPTS+= src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
