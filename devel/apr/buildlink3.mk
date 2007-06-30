# $NetBSD: buildlink3.mk,v 1.31 2007/06/30 15:04:55 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.apr+=	apr>=1.2.8
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr
BUILDLINK_INCDIRS.apr?=		include/apr-1

BUILDLINK_FILES.apr+=	bin/apr-1-config
BUILDLINK_FILES.apr+=	lib/apr.exp

${BUILDLINK_DIR}/bin/apr-config: buildlink-directories
	${MKDIR} ${BUILDLINK_DIR}/bin && ${LN} -fs apr-1-config ${BUILDLINK_DIR}/bin/apr-config

buildlink-apr-cookie: ${BUILDLINK_DIR}/bin/apr-config

.endif	# APR_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
