# $NetBSD: buildlink3.mk,v 1.32 2009/03/20 19:24:09 joerg Exp $

BUILDLINK_TREE+=	apr

.if !defined(APR_BUILDLINK3_MK)
APR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr+=	apr>=1.2.8
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr
BUILDLINK_INCDIRS.apr?=		include/apr-1

BUILDLINK_FILES.apr+=	bin/apr-1-config
BUILDLINK_FILES.apr+=	lib/apr.exp

${BUILDLINK_DIR}/bin/apr-config: buildlink-directories
	${MKDIR} ${BUILDLINK_DIR}/bin && ${LN} -fs apr-1-config ${BUILDLINK_DIR}/bin/apr-config

buildlink-apr-cookie: ${BUILDLINK_DIR}/bin/apr-config
.endif # APR_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr
