# $NetBSD: buildlink3.mk,v 1.1 2010/07/09 18:08:05 asau Exp $

# BUILDLINK_DEPMETHOD.clisp?=	build # -- not checked yet

BUILDLINK_TREE+=	clisp

.if !defined(CLISP_BUILDLINK3_MK)
CLISP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clisp+=	clisp>=2.49
BUILDLINK_PKGSRCDIR.clisp?=	../../lang/clisp

.endif	# CLISP_BUILDLINK3_MK

BUILDLINK_TREE+=	-clisp
