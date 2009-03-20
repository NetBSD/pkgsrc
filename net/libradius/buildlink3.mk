# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:10 joerg Exp $

BUILDLINK_TREE+=	libradius

.if !defined(LIBRADIUS_BUILDLINK3_MK)
LIBRADIUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libradius+=	libradius>=20040827
BUILDLINK_PKGSRCDIR.libradius?=	../../net/libradius
BUILDLINK_DEPMETHOD.libradius?=	build

.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "FreeBSD"
BUILDLINK_LDADD.libradius+=	-lmd
BUILDLINK_LDFLAGS.libradius?=	${BUILDLINK_LDADD.libradius}
.  endif
.endif # LIBRADIUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libradius
