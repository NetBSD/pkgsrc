# $NetBSD: buildlink3.mk,v 1.7 2005/03/18 19:57:31 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL74_LIB_BUILDLINK3_MK:=	${POSTGRESQL74_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql74-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql74-lib}
BUILDLINK_PACKAGES+=	postgresql74-lib

.if !empty(POSTGRESQL74_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql74-lib+=		postgresql{74,}-lib>=7.4.0
BUILDLINK_RECOMMENDED.postgresql74-lib+=	postgresql74-lib>=7.4.3
BUILDLINK_PKGSRCDIR.postgresql74-lib?=	../../databases/postgresql74-lib
BUILDLINK_INCDIRS.postgresql74-lib?=	include/postgresql

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql74-lib=	-lpq ${BUILDLINK_LDADD.gettext}
.endif	# POSTGRESQL74_LIB_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
