# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBBONOBO_BUILDLINK3_MK:=	${LIBBONOBO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbonobo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibbonobo}
BUILDLINK_PACKAGES+=	libbonobo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libbonobo

.if !empty(LIBBONOBO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libbonobo+=	libbonobo>=2.8.0
BUILDLINK_ABI_DEPENDS.libbonobo+=	libbonobo>=2.10.1nb2
BUILDLINK_PKGSRCDIR.libbonobo?=	../../devel/libbonobo

BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-2.0/*
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-activation-2.0/*

PRINT_PLIST_AWK+=	/^@dirrm lib\/bonobo$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bonobo\/(monikers|servers)$$/ \
				{ print "@comment in libbonobo: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bonobo-2.0\/samples$$/ \
				{ print "@comment in libbonobo: " $$0; next; }
.endif	# LIBBONOBO_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
