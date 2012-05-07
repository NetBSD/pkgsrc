# $NetBSD: buildlink3.mk,v 1.2 2012/05/07 01:53:41 dholland Exp $

BUILDLINK_TREE+=	openjdk7-bin

.if !defined(OPENJDK7_BIN_BUILDLINK3_MK)
OPENJDK7_BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjdk7-bin+=	openjdk7-bin-[0-9]*
BUILDLINK_ABI_DEPENDS.openjdk7-bin+=	openjdk7-bin>=6.0.4
BUILDLINK_PKGSRCDIR.openjdk7-bin?=	../../lang/openjdk7-bin
BUILDLINK_JAVA_PREFIX.openjdk7-bin=	${PREFIX}/java/openjdk7-bin

UNLIMIT_RESOURCES+=	datasize	# Must be at least 131204
.endif # OPENJDK7_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk7-bin
