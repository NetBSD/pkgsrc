# $NetBSD: buildlink3.mk,v 1.5 2004/04/01 18:18:00 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBBONOBO_BUILDLINK3_MK:=	${LIBBONOBO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonobo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibbonobo}
BUILDLINK_PACKAGES+=	libbonobo

.if !empty(LIBBONOBO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libbonobo+=	libbonobo>=2.6.0
BUILDLINK_PKGSRCDIR.libbonobo?=	../../devel/libbonobo

BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-2.0/*
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-activation-2.0/*
.endif	# LIBBONOBO_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
