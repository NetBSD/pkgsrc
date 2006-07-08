# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCP_WRAPPERS_BUILDLINK3_MK:=	${TCP_WRAPPERS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcp_wrappers
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcp_wrappers}
BUILDLINK_PACKAGES+=	tcp_wrappers
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tcp_wrappers

.if !empty(TCP_WRAPPERS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcp_wrappers+=	tcp_wrappers>=7.6.1nb1
BUILDLINK_ABI_DEPENDS.tcp_wrappers+=	tcp_wrappers>=7.6.1nb3
BUILDLINK_PKGSRCDIR.tcp_wrappers?=	../../security/tcp_wrappers
.endif	# TCP_WRAPPERS_BUILDLINK3_MK

# need libnsl and libsocket to link into an executable on Solaris.
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.tcp_wrappers+=		-lnsl -lsocket
BUILDLINK_LDFLAGS.tcp_wrappers?=	${BUILDLINK_LDADD.tcp_wrappers}
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
