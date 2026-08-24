# $NetBSD: Makefile,v 1.40 2026/08/24 08:42:22 adam Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
PKGREVISION=	13
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_PDU=ON

REPLACE_PYTHON+=	gr-pdu/python/pdu/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
