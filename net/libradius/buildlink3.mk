# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:27 rillig Exp $

BUILDLINK_TREE+=	libradius

.if !defined(LIBRADIUS_BUILDLINK3_MK)
LIBRADIUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libradius+=	libradius>=20040827
BUILDLINK_PKGSRCDIR.libradius?=		../../net/libradius
BUILDLINK_DEPMETHOD.libradius?=		build

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "FreeBSD"
BUILDLINK_LDADD.libradius+=	-lmd
BUILDLINK_LDFLAGS.libradius?=	${BUILDLINK_LDADD.libradius}
.endif
.endif # LIBRADIUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libradius
