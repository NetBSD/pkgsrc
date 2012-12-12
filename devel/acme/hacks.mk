# $NetBSD: hacks.mk,v 1.1 2012/12/12 10:12:38 wiz Exp $

.if !defined(ACME_HACKS_MK)
ACME_HACKS_MK=	# defined

.  if ${OPSYS} == "HPUX"
PKG_HACKS+=		hpux-cpu_t
SUBST_CLASSES+=		cpu_t
SUBST_STAGE.cpu_t=	pre-configure
SUBST_MESSAGE.cpu_t=	Changing conflicting type cpu_t to acmecpu_t
SUBST_FILES.cpu_t=	cpu.c cpu.h
SUBST_SED.cpu_t=	-e 's,cpu_t,acmecpu_t,g'
.  endif

.endif
