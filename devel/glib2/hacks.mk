# $NetBSD: hacks.mk,v 1.3 2008/07/14 16:45:53 tron Exp $

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	# defined

# "glib2" supports support for Universal Binaries. But a lot of packages
# using it (e.g. "gtk2+") don't support it. We therefore disable it.

.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "Darwin"
PKG_HACKS+=	darwin-no-universal
.    if ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ENV+=	ac_cv_c_bigendian=yes
.    else
CONFIGURE_ENV+=	ac_cv_c_bigendian=no
.    endif
.  endif

.endif
