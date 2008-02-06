# $NetBSD: buildlink3.mk,v 1.2 2008/02/06 10:08:01 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OSSP_JS_BUILDLINK3_MK:=	${OSSP_JS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ossp-js
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nossp-js}
BUILDLINK_PACKAGES+=	ossp-js
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ossp-js

.if ${OSSP_JS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ossp-js+=	ossp-js>=1.6.20070208nb1
BUILDLINK_PKGSRCDIR.ossp-js?=	../../lang/ossp-js
.  include "../../lang/ossp-js/libm.mk"
.endif	# OSSP_JS_BUILDLINK3_MK

.include "../../mk/dlopen/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
