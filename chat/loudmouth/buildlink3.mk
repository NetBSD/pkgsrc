# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/20 14:16:19 jmmv Exp $
#
# This Makefile fragment is included by packages that use loudmouth.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LOUDMOUTH_BUILDLINK3_MK:=	${LOUDMOUTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	loudmouth
.endif

.if !empty(LOUDMOUTH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			loudmouth
BUILDLINK_DEPENDS.loudmouth+=		loudmouth>=0.10.1
BUILDLINK_PKGSRCDIR.loudmouth?=		../../chat/loudmouth

.include "../../mk/bsd.prefs.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
BUILDLINK_DEPENDS.gnutls=	gnutls>=1.0.0
.include "../../security/gnutls/buildlink3.mk"
.endif

.endif # LOUDMOUTH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
