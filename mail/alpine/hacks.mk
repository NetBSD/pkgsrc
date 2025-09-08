# $NetBSD: hacks.mk,v 1.1 2025/09/08 18:16:55 vins Exp $

.if !defined(ALPINE_HACKS_MK)
ALPINE_HACKS_MK=	defined

### [Mon Sept 8 17:32:19 UTC 2025 : vins]
### GCC14 enforces `-Werror=incompatible-pointer-type', which makes alpine
### build fail on SunOS. This is essentially due to bitrotting code in the
### OS-dependent routines for Solaris, inside the alpine codebase.
### The rationale of using SUBST here is to avoid maintaining multiple
### patches addressing the same issue.
### It should be a temporary solution until the problem is reported upstream.

.if ${OPSYS} == "SunOS"

PKG_HACKS+=		incompatible-pointer-types

SUBST_CLASSES+=		hacks
SUBST_STAGE.hacks=	pre-configure
SUBST_MESSAGE.hacks=	Applying fixes for OS-dependent routines on SunOS.
SUBST_FILES.hacks+=	imap/src/osdep/unix/news.c imap/src/osdep/unix/mh.c \
			imap/src/osdep/unix/mix.c imap/src/osdep/unix/mx.c \
			imap/src/osdep/unix/maildir.c imap/src/osdep/unix/maildir.h \
			imap/src/osdep/unix/os_soln.h imap/src/osdep/unix/scandir.c
SUBST_SED.hacks+=	-e "s:const struct direct \*name:struct direct \*name:g"
SUBST_SED.hacks+=	-e "s:void \*d1:const void \*d1:g"
SUBST_SED.hacks+=	-e "s:void \*d2:const void \*d2:g"
SUBST_SED.hacks+=	-e "s:const struct direct \**d1:const void \*d1:g"
SUBST_SED.hacks+=	-e "s:const struct direct \**d2:const void \*d2:g"

.endif
.endif  # ALPINE_HACKS_MK
