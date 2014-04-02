# $NetBSD: hacks.mk,v 1.1 2014/04/02 12:49:25 obache Exp $

.if !defined(BINUTILS_MIPS_CURRENT_HACKS_MK)
BINUTILS_MIPS_CURRENT_HACKS_MK=	# defined

#
# Hit a bug of /bin/sh in NetBSD-6 release or prior.
# PR pkg/48695
#
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-*) \
	&& empty(MACHINE_PLATFORM:MNetBSD-6.99-*-*)
CONFIG_SHELL=	/bin/ksh
.endif

.endif	# BINUTILS_MIPS_CURRENT_HACKS_MK
