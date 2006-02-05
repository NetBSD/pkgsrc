# $NetBSD: buildlink3.mk,v 1.9 2006/02/05 23:10:22 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT2_BUILDLINK3_MK:=	${ORBIT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NORBit2}
BUILDLINK_PACKAGES+=	ORBit2

.if !empty(ORBIT2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ORBit2+=	ORBit2>=2.12.0
BUILDLINK_RECOMMENDED.ORBit2?=	ORBit2>=2.12.4nb1
BUILDLINK_PKGSRCDIR.ORBit2?=	../../net/ORBit2

PRINT_PLIST_AWK+=	/^@dirrm lib\/orbit-2.0$$/ \
				{ print "@comment in ORBit2: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/idl$$/ \
				{ print "@comment in ORBit2: " $$0; next; }
.endif	# ORBIT2_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
