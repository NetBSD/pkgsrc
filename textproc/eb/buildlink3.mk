# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EB_BUILDLINK3_MK:=	${EB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neb}
BUILDLINK_PACKAGES+=	eb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}eb

_EB_REQD=		3.3.2nb1

# This variable should be directly passed to shell commands.  (E.g., a
# configure argument.)
#
# XXX We need something generic.
.include "../../mk/bsd.prefs.mk"
PKG_SYSCONFDIR.eb=$$(						\
	if ${PKG_ADMIN} pmatch 'eb>=${_EB_REQD}'		\
	    $$( ${PKG_INFO} -e eb ) 2>/dev/null; then		\
		${PKG_INFO} -B eb 2>/dev/null |			\
		    ${SED} -ne '/^PKG_SYSCONFDIR/		\
			{ s/^PKG_SYSCONFDIR=//; p; }';		\
	else ${ECHO}; fi )

.if !empty(EB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.eb+=		eb>=${_EB_REQD}
BUILDLINK_ABI_DEPENDS.eb+=	eb>=4.1.3nb1
BUILDLINK_PKGSRCDIR.eb?=	../../textproc/eb
.endif	# EB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
