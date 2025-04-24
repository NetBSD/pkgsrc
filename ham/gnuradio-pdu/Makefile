# $NetBSD: Makefile,v 1.29 2025/04/24 14:14:44 wiz Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
PKGREVISION=	2
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_PDU=ON

REPLACE_PYTHON+=	gr-pdu/python/pdu/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
