# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIB_BUILDLINK3_MK:=	${GLIB_BUILDLINK3_MK}+

.if !empty(GLIB_BUILDLINK3_MK:M\+)
BUILDLINK_DEPENDS.glib?=	glib>=1.2.10nb5
BUILDLINK_PKGSRCDIR.glib?=	../../devel/glib
.endif	# GLIB_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	glib
.endif

.if !empty(GLIB_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	glib

PTHREAD_OPTS+=	require

.  include "../../mk/pthread.buildlink3.mk"
.endif	# GLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
