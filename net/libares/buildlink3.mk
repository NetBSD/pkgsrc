# $NetBSD: buildlink3.mk,v 1.3 2005/03/12 05:42:48 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBARES_BUILDLINK3_MK:=	${LIBARES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libares
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibares}
BUILDLINK_PACKAGES+=	libares

.include "../../mk/bsd.prefs.mk"

.if !empty(LIBARES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libares+=	libares>=1.1.1
BUILDLINK_PKGSRCDIR.libares?=	../../net/libares
BUILDLINK_DEPMETHOD.libares?=	build
.endif	# LIBARES_BUILDLINK3_MK

.if ${OPSYS} == "Interix"
BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/bind /usr/local/lib/bind
BUILDLINK_CPPFLAGS.libares+=	-I/usr/local/include/bind
BUILDLINK_LDFLAGS.libares+=	-L/usr/local/lib/bind
BUILDLINK_LIBS.libares+=	-lbind -ldb
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
