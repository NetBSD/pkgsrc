# $NetBSD: pf.buildlink3.mk,v 1.3 2015/01/14 20:40:32 rumko Exp $
#
# Makefile fragment for packages using pf.
#
# The following variables are set by this file:
#
#   PFVAR_H	The path to the pfvar.h header file.
#   PFCTL	The path to the pfctl program.
#   PF_VERSION	The detected PF version (as in OpenBSD).
#

.if !defined(PF_BUILDLINK3_MK)
PF_BUILDLINK3_MK=	#defined

.include "../../mk/bsd.fast.prefs.mk"

# Platforms where pf is available on.
ONLY_FOR_PLATFORM?=	NetBSD-[3-9]*-* OpenBSD-[3-9]*-* FreeBSD-*-* \
			DragonFly-*-*

# Detect the pfvar.h header.
.if exists(/usr/include/net/pfvar.h)
_PFVAR_H=	/usr/include/net/pfvar.h	
.elif exists(/usr/include/net/pf/pfvar.h)
_PFVAR_H=	/usr/include/net/pf/pfvar.h
.else
PKG_FAIL_REASON+=	"Couldn't find pfvar.h header; please make sure that this header is available in /usr/include/net."
.endif

PFVAR_H?=	${_PFVAR_H}
PFCTL?=		/sbin/pfctl

# Compute the version number of the PF API by checking for the presence
# of symbols added in newer versions and store the result in ${PF_VERSION}.

# Default to the first version with PF, which was OpenBSD 3.0.
PF_VERSION=	3.0

.if !empty(PFVAR_H)
# OpenBSD 4.7: pf_state_rm_src_node added
_PF_4_7!=	${GREP} -c pf_state_rm_src_node ${PFVAR_H} || ${TRUE}
# OpenBSD 4.6: pf_normalize_mss added
_PF_4_6!=	${GREP} -c pf_normalize_mss ${PFVAR_H} || ${TRUE}
# OpenBSD 4.5: pf_send_deferred_syn added
_PF_4_5!=	${GREP} -c pf_send_deferred_syn ${PFVAR_H} || ${TRUE}
# OpenBSD 4.4: pf_match_tag added
_PF_4_4!=	${GREP} -c pf_match_tag ${PFVAR_H} || ${TRUE}
# OpenBSD 4.3: pf_match_addr_range added
_PF_4_3!=	${GREP} -c pf_match_addr_range ${PFVAR_H} || ${TRUE}
# OpenBSD 4.2: pf_statelist added
_PF_4_2!=	${GREP} -c pf_statelist ${PFVAR_H} || ${TRUE}
# OpenBSD 4.1: PF_OSFP_INET6 added
_PF_4_1!=	${GREP} -c PF_OSFP_INET6 ${PFVAR_H} || ${TRUE}
# OpenBSD 3.8: pf_socket_lookup added
_PF_3_8!=	${GREP} -c pf_socket_lookup ${PFVAR_H} || ${TRUE}
# OpenBSD 3.7: pf_threshold added
_PF_3_7!=	${GREP} -c pf_threshold ${PFVAR_H} || ${TRUE}
# OpenBSD 3.6: pf_cksum_fixup added
_PF_3_6!=	${GREP} -c pf_cksum_fixup ${PFVAR_H} || ${TRUE}
# OpenBSD 3.5: pfi_lookup_if added
_PF_3_5!=	${GREP} -c pfi_lookup_if ${PFVAR_H} || ${TRUE}

.    if ${_PF_4_7} != "0"
PF_VERSION=	4.7
.    elif ${_PF_4_6} != "0"
PF_VERSION=	4.6
.    elif ${_PF_4_5} != "0"
PF_VERSION=	4.5
.    elif ${_PF_4_4} != "0"
PF_VERSION=	4.4
.    elif ${_PF_4_3} != "0"
PF_VERSION=	4.3
.    elif ${_PF_4_2} != "0"
PF_VERSION=	4.2
.    elif ${_PF_4_1} != "0"
PF_VERSION=	4.1
.    elif ${_PF_3_8} != "0"
PF_VERSION=	3.8
.    elif ${_PF_3_7} != "0"
PF_VERSION=	3.7
.    elif ${_PF_3_6} != "0"
PF_VERSION=	3.6
.    elif ${_PF_3_5} != "0"
PF_VERSION=	3.5
.    endif
.endif

.endif  # PF_BUILDLINK3_MK
