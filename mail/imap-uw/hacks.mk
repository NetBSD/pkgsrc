# $NetBSD: hacks.mk,v 1.3 2025/10/26 17:28:47 vins Exp $

.if !defined(IMAP_UW_HACKS_MK)
IMAP_UW_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [Thu Jan 23 01:28:36 2003 UTC : dmcmahill]
### On PowerPC, building with optimisation with GCC causes an "attempt
### to free unreference scalar".  Remove optimisation flags as a
### workaround until GCC is fixed.
###
.if !empty(CC_VERSION:Mgcc*) && !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
PKG_HACKS+=		alpha-codegen
BUILDLINK_TRANSFORM+=	opt:-O[0-9]*:-O
.endif

### [Mon Sept 8 17:32:19 UTC 2025 : vins]
### GCC14 enforces `-Werror=incompatible-pointer-type', which makes imap-uw
### build fail on SunOS. This is essentially due to bitrotting code in the
### OS-dependent routines for Solaris, inside the imap-uw codebase.
### The rationale of using SUBST here is to avoid maintaining multiple
### patches addressing the same issue.

.if ${OPSYS} == "SunOS"

PKG_HACKS+=		incompatible-pointer-types

SUBST_CLASSES+=		hacks
SUBST_STAGE.hacks=	pre-configure
SUBST_MESSAGE.hacks=	Applying fixes for OS-dependent routines on SunOS.
SUBST_FILES.hacks+=	src/osdep/unix/news.c src/osdep/unix/mh.c \
			src/osdep/unix/mix.c src/osdep/unix/mx.c \
			src/osdep/unix/os_soln.h src/osdep/unix/scandir.c
SUBST_SED.hacks+=	-e "s:const struct direct \*name:struct direct \*name:g"
SUBST_SED.hacks+=	-e "s:void \*d1:const void \*d1:g"
SUBST_SED.hacks+=	-e "s:void \*d2:const void \*d2:g"
SUBST_SED.hacks+=	-e "s:const struct direct \**d1:const void \*d1:g"
SUBST_SED.hacks+=	-e "s:const struct direct \**d2:const void \*d2:g"

.endif
.endif  # IMAP_UW_HACKS_MK
