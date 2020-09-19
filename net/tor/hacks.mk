# $NetBSD: hacks.mk,v 1.1 2020/09/19 18:22:01 leot Exp $

.if !defined(TOR_HACKS_MK)
TOR_HACKS_MK=	defined

# [Sat Sep 19 15:51:04 UTC 2020 : leot]
# On NetBSD/evbarm - and only on netbsd-9 - calling backtrace(3) ends
# up in a SIGSEGV, documented via PR port-evbarm/55669.
# To reproduce with Tor, after removing this hack, calling
# `tor --version' should ends up in the Tor process hanging forever
# (instead printing the version to the stdout).
.if !empty(MACHINE_PLATFORM:MNetBSD-9.*-*arm*)
PKG_HACKS+=		disable-backtrace
CONFIGURE_ENV+=		ac_cv_search_backtrace=no
.endif

.endif	# TOR_HACKS_MK
