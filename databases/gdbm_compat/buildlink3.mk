# $NetBSD: buildlink3.mk,v 1.4 2012/01/24 09:10:51 sbd Exp $
#

BUILDLINK_TREE+=	gdbm_compat

.if !defined(GDBM_COMPAT_BUILDLINK3_MK)
GDBM_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm_compat+=	gdbm_compat>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm_compat+=	gdbm_compat>=1.10
BUILDLINK_PKGSRCDIR.gdbm_compat?=	../../databases/gdbm_compat

# Look like real ndbm.
BUILDLINK_TRANSFORM+=	l:ndbm:gdbm_compat:gdbm

.include "../../databases/gdbm/buildlink3.mk"
.endif	# GDBM_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm_compat
