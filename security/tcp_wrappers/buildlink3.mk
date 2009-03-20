# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:25:23 joerg Exp $

BUILDLINK_TREE+=	tcp_wrappers

.if !defined(TCP_WRAPPERS_BUILDLINK3_MK)
TCP_WRAPPERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcp_wrappers+=	tcp_wrappers>=7.6.1nb1
BUILDLINK_ABI_DEPENDS.tcp_wrappers+=	tcp_wrappers>=7.6.1nb3
BUILDLINK_PKGSRCDIR.tcp_wrappers?=	../../security/tcp_wrappers

# need libnsl and libsocket to link into an executable on Solaris.
.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.tcp_wrappers+=		-lnsl -lsocket
BUILDLINK_LDFLAGS.tcp_wrappers?=	${BUILDLINK_LDADD.tcp_wrappers}
.endif
.endif # TCP_WRAPPERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcp_wrappers
