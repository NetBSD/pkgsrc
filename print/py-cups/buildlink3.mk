# $NetBSD: buildlink3.mk,v 1.11 2012/05/07 01:53:55 dholland Exp $

BUILDLINK_TREE+=	py-cups

.if !defined(PY_CUPS_BUILDLINK3_MK)
PY_CUPS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cups+=	${PYPKGPREFIX}-cups>=1.9.44
BUILDLINK_ABI_DEPENDS.py-cups+=	${PYPKGPREFIX}-cups>=1.9.47nb3
BUILDLINK_PKGSRCDIR.py-cups?=	../../print/py-cups

#.include "../../print/cups/buildlink3.mk"
.endif # PY_CUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cups
