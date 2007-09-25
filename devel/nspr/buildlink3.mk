# $NetBSD: buildlink3.mk,v 1.9 2007/09/25 04:18:25 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NSPR_BUILDLINK3_MK:=	${NSPR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	nspr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnspr}
BUILDLINK_PACKAGES+=	nspr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}nspr

.if ${NSPR_BUILDLINK3_MK} == "+"

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.4.1nb1
.  if ${OPSYS} == "Darwin"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.6.1nb3
.  else
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.6.1nb1
.  endif

BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr
BUILDLINK_FILES.nspr+=          lib/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*

BUILDLINK_INCDIRS.nspr+=        include/nspr
BUILDLINK_LIBDIRS.nspr+=        lib/nspr
BUILDLINK_RPATHDIRS.nspr+=      lib/nspr

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
