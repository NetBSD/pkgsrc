# $NetBSD: buildlink3.mk,v 1.4 2004/12/06 09:09:48 uebayasi Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EB_BUILDLINK3_MK:=	${EB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neb}
BUILDLINK_PACKAGES+=	eb

_EB_REQD=		3.3.2nb1

# XXX We need something generic.
.include "../../mk/bsd.prefs.mk"
PKG_SYSCONFDIR.eb!=						\
	if ${PKG_ADMIN} pmatch 'eb>=${_EB_REQD}' 2>/dev/null; then \
		${PKG_INFO} -B eb 2>/dev/null |			\
		    ${SED} -ne '/^PKG_SYSCONFDIR/ {		\
			s/^PKG_SYSCONFDIR=//; p; }';		\
	else							\
		${ECHO};					\
	fi

.if !empty(EB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.eb+=		eb>=${_EB_REQD}
BUILDLINK_RECOMMENDED.eb+=	eb>=3.3.4nb1
BUILDLINK_PKGSRCDIR.eb?=	../../textproc/eb
.endif	# EB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
