# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:13:33 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SWIG_PYTHON_BUILDLINK3_MK:=	${SWIG_PYTHON_BUILDLINK3_MK}+

PYTHON_VERSION_ACCEPTED=	22 22pth

.include "../../lang/python/pyversion.mk"
.include "../../devel/swig-build/Makefile.version"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swig-python
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswig-python}
BUILDLINK_PACKAGES+=	swig-python

.if !empty(SWIG_PYTHON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swig-python+=		swig-python>=${SWIG_VERSION}
BUILDLINK_RECOMMENDED.swig-python+=	swig-python>=1.3.19nb1
BUILDLINK_PKGSRCDIR.swig-python?=	../../devel/swig-python
.endif	# SWIG_PYTHON_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
