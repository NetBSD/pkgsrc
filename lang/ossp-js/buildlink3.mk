# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:24:51 joerg Exp $

BUILDLINK_TREE+=	ossp-js

.if !defined(OSSP_JS_BUILDLINK3_MK)
OSSP_JS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-js+=	ossp-js>=1.6.20070208nb1
BUILDLINK_PKGSRCDIR.ossp-js?=	../../lang/ossp-js
.  include "../../lang/ossp-js/libm.mk"

.include "../../mk/dlopen.buildlink3.mk"
.endif # OSSP_JS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-js
