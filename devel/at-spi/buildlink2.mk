# $NetBSD: buildlink2.mk,v 1.4 2004/04/01 18:30:41 jmmv Exp $
#
# This Makefile fragment is included by packages that use at-spi.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(AT_SPI_BUILDLINK2_MK)
AT_SPI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			at-spi
BUILDLINK_DEPENDS.at-spi?=		at-spi>=1.4.0
BUILDLINK_PKGSRCDIR.at-spi?=		../../devel/at-spi

EVAL_PREFIX+=	BUILDLINK_PREFIX.at-spi=at-spi
BUILDLINK_PREFIX.at-spi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.at-spi+=	include/at-spi-1.0/cspi/*.h
BUILDLINK_FILES.at-spi+=	include/at-spi-1.0/libspi/*.h
BUILDLINK_FILES.at-spi+=	lib/libcspi.*
BUILDLINK_FILES.at-spi+=	lib/libspi.*

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gail/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	at-spi-buildlink

at-spi-buildlink: _BUILDLINK_USE

.endif	# AT_SPI_BUILDLINK2_MK
