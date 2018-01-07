# $NetBSD: buildlink3.mk,v 1.5 2018/01/07 13:04:20 rillig Exp $

BUILDLINK_TREE+=	ossp-js

.if !defined(OSSP_JS_BUILDLINK3_MK)
OSSP_JS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-js+=	ossp-js>=1.6.20070208nb1
BUILDLINK_PKGSRCDIR.ossp-js?=	../../lang/ossp-js
.include "../../lang/ossp-js/libm.mk"

.include "../../mk/dlopen.buildlink3.mk"
.endif # OSSP_JS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-js
