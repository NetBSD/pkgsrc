# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 17:30:10 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_AT_SPI_BUILDLINK3_MK:=	${PY_AT_SPI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-at-spi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-at-spi}
BUILDLINK_PACKAGES+=	py-at-spi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-at-spi

.if ${PY_AT_SPI_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-at-spi+=	${PYPKGPREFIX}-at-spi>=1.20.1
BUILDLINK_PKGSRCDIR.py-at-spi?=		../../devel/py-at-spi
.endif	# PY_AT_SPI_BUILDLINK3_MK

.include "../../devel/at-spi/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
