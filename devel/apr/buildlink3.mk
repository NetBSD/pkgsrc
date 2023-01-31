# $NetBSD: buildlink3.mk,v 1.37 2023/01/31 18:41:49 wiz Exp $

BUILDLINK_TREE+=	apr

.if !defined(APR_BUILDLINK3_MK)
APR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr+=	apr>=1.5.0
BUILDLINK_ABI_DEPENDS.apr+=	apr>=1.5.0
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr
BUILDLINK_INCDIRS.apr?=		include/apr-1

BUILDLINK_FILES.apr+=	bin/apr-1-config
BUILDLINK_FILES.apr+=	lib/apr.exp

${BUILDLINK_DIR}/bin/apr-config: buildlink-directories
	${MKDIR} ${BUILDLINK_DIR}/bin && ${LN} -fs apr-1-config ${BUILDLINK_DIR}/bin/apr-config

.PHONY: buildlink-apr-cookie
buildlink-apr-cookie: ${BUILDLINK_DIR}/bin/apr-config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.endif # APR_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr
