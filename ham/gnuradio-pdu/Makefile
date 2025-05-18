# $NetBSD: Makefile,v 1.30 2025/05/18 19:31:20 gdt Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
PKGREVISION=	3
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_PDU=ON

REPLACE_PYTHON+=	gr-pdu/python/pdu/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
