# $NetBSD: Makefile,v 1.37 2026/05/15 09:58:53 adam Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
PKGREVISION=	10
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_PDU=ON

REPLACE_PYTHON+=	gr-pdu/python/pdu/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
