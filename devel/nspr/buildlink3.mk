# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

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
.endif # NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
