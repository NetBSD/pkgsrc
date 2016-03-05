# $NetBSD: buildlink3.mk,v 1.17 2016/03/05 11:27:44 jperkin Exp $

BUILDLINK_TREE+=	apr-util

.if !defined(APR_UTIL_BUILDLINK3_MK)
APR_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr-util+=	apr-util>=1.2.8
BUILDLINK_ABI_DEPENDS.apr-util+=	apr-util>=1.5.4nb4
BUILDLINK_PKGSRCDIR.apr-util?=	../../devel/apr-util

BUILDLINK_FILES.apr-util+=	bin/apu-1-config
BUILDLINK_FILES.apr-util+=	lib/aprutil.exp

${BUILDLINK_DIR}/bin/apu-config: buildlink-directories
	${MKDIR} ${BUILDLINK_DIR}/bin && ${LN} -fs apu-1-config ${BUILDLINK_DIR}/bin/apu-config

buildlink-apr-util-cookie: ${BUILDLINK_DIR}/bin/apu-config

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := apr-util
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.apr-util:Mdb4)
BDB_ACCEPTED?=		db4 db5
.  include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.apr-util:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # APR_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr-util
