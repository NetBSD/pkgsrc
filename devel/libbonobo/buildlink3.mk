# $NetBSD: buildlink3.mk,v 1.2 2004/02/11 03:52:22 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libbonobo.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBBONOBO_BUILDLINK3_MK:=	${LIBBONOBO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonobo
.endif

.if !empty(LIBBONOBO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libbonobo
BUILDLINK_DEPENDS.libbonobo+=		libbonobo>=2.4.2
BUILDLINK_PKGSRCDIR.libbonobo?=		../../devel/libbonobo

BUILDLINK_FILES.libbonobo+=		share/idl/bonobo-2.0/*
BUILDLINK_FILES.libbonobo+=		share/idl/bonobo-activation-2.0/*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBBONOBO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
