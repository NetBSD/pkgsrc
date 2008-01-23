# $NetBSD: buildlink3.mk,v 1.29 2008/01/23 17:35:20 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GETTEXT_BUILDLINK3_MK:=	${GETTEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext}
BUILDLINK_PACKAGES+=	gettext
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gettext

.if !empty(GETTEXT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.14.5
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib
.endif	# GETTEXT_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

CHECK_BUILTIN.gettext:=	yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no

.if !empty(USE_BUILTIN.gettext:M[nN][oO])
.  include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
