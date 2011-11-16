# $NetBSD: hacks.mk,v 1.1 2011/11/16 03:13:28 minskim Exp $

.if !defined(CAIRO_HACKS_MK)
CAIRO_HACKS_MK=	defined

###
### A workaround for MacPorts Ticket #31469
### https://trac.macports.org/ticket/31469
###
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
_BAD_GCC_BUILD!=	${CC} --version | (${GREP} -c 'i686-apple-darwin11-llvm-gcc-4\.2\ .*build\ 5658' || ${TRUE})
.  if ${_BAD_GCC_BUILD} == "1"
PKG_HACKS+=	llvm-link
CONFIGURE_ENV+=	ac_cv_prog_CC=gcc-4.2
.  endif
.endif

.endif	# CAIRO_HACKS_MK
