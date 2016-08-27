# $NetBSD: hacks.mk,v 1.6 2016/08/27 08:38:31 maya Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### On NetBSD/amd64 7.99.26, gcc optimisation, at least for version 5.x,
### produces, a "temacs" binary which segfaults.
###
.  if !empty(MACHINE_PLATFORM:MNetBSD-*)
.    if !empty(CC_VERSION:Mgcc-5.*)
PKG_HACKS+=		optimisation
CFLAGS+=		-fno-optimize-strlen
.    endif
.  endif

### PaX is enabled, bootstrap-emacs command dumps core with segfault.
### emacs-24.5/src/Makefile.in does not support NetBSD paxctl(8) syntax.
### http://debbugs.gnu.org/cgi/bugreport.cgi?bug=23371
###
.  if !empty(MACHINE_PLATFORM:MNetBSD-*)
.    if exists(/usr/sbin/paxctl)
SUBST_CLASSES+=			paxctl
SUBST_STAGE.paxctl=		pre-configure
SUBST_MESSAGE.paxctl=		Setting paxctl command
SUBST_FILES.paxctl+=		src/Makefile.in
SUBST_SED.paxctl+=		-e 's,test "X$$(PAXCTL)" = X || $$(PAXCTL) -zex,/usr/sbin/paxctl +a,g'
SUBST_SED.paxctl+=		-e 's,test "X$$(PAXCTL)" = X || $$(PAXCTL) -r,/usr/sbin/paxctl +a,g'
.    endif
.  endif

.endif  # EMACS_HACKS_MK
