# $NetBSD: hacks.mk,v 1.2 2015/04/28 14:34:20 fhajny Exp $

.if !defined(ERLANG_HACKS_MK)
ERLANG_HACKS_MK=	# empty

###
### Building this with -O3 could be asking for trouble.
###
BUILDLINK_TRANSFORM+=	opt:-O3:-O2

.include "../../mk/bsd.fast.prefs.mk"

###
### XXX Don't let the kernel put the map elsewhere.
###
.if (${OPSYS} == "NetBSD"  || \
     ${OPSYS} == "OpenBSD" || \
     ${OPSYS} == "FreeBSD" || \
     ${OPSYS} == "SunOS")
CFLAGS+=	-DMMAP_MAP_FIXED
.endif

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.endif
