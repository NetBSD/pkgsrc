# $NetBSD: hacks.mk,v 1.2.4.1 2012/06/01 12:29:32 tron Exp $

.if !defined(CAIRO_HACKS_MK)
CAIRO_HACKS_MK=	defined

###
### A workaround for MacPorts Ticket #31469
### https://trac.macports.org/ticket/31469
###
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
_BAD_GCC_BUILD!=	${CC} --version | (${GREP} -c 'i686-apple-darwin11-llvm-gcc-4\.2\ .*build\ 5658' || ${TRUE})
.  if ${_BAD_GCC_BUILD} == "1" && exists(/usr/bin/gcc-4.2)
PKG_HACKS+=	llvm-link
CONFIGURE_ENV+=	ac_cv_prog_CC=gcc-4.2
.  endif
.endif

#
# Workaround for "the pixman problem" with netbsd-5 native X. The
# problem is that if the order of rpath options isn't right when
# linking client programs (right being /usr/pkg before /usr/X11R7),
# the native pixman library gets pulled in instead of the pkgsrc one,
# and then the link fails with undefined symbols from cairo; these are
# symbols that are present only in the newer pkgsrc pixman. The
# problem with rpath options and ordering is complicated by there
# being multiple ways of writing them (-R, -Wl,-rpath, etc.) and as
# many packages just blat out flags from various sources they don't
# necessarily match or come out in the right order.
#
# Some cases of "the pixman problem" were solved with one set of
# changes a month ago or so, but other packages still fail for the
# reasons cited. In the absence of a wrappers-based general solution
# to keep the order correct, most or all remaining instances can be
# solved by explicitly adding the necessary pixman lib to the link
# line instead of pulling it in via cairo's dependency on it. Or at
# least, this fixes the build. It should also make the right things
# happen during library search (I think) but that's less clear. I hate
# ELF.
#
# The best way to explicitly add pixman to the link line is to hack it
# into cairo's .pc file. This is what we do here.
#
# Note that this hack is also required for 5.99 earlier than whatever
# point the necessary updates to X were applied. I'm assuming this is
# old enough that nobody's going to care.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*) && \
    empty(MACHINE_PLATFORM:MNetBSD-5.99.*)
SUBST_CLASSES+=		pixman
SUBST_STAGE.pixman=	post-build
SUBST_MESSAGE.pixman=	Hacking pixman into cairo.pc for the "pixman problem".
SUBST_FILES.pixman=	src/cairo.pc
SUBST_SED.pixman=	-e '/^Libs:/s/-lcairo/-lcairo -lpixman-1/'
.endif

.endif	# CAIRO_HACKS_MK
