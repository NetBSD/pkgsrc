# $NetBSD: hacks.mk,v 1.1 2007/01/09 21:03:02 tv Exp $

### [Tue Jan  9 15:57:05 EST 2007 : tv]
### Interix has u_int64_t, but not uint64_t
### (gdevpdfe.c doesn't use the autoconf test based int64 type,
### but absolutely requires a 64-bit unsigned int)
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		interix-uint64_t
CPPFLAGS.Interix+=	-Duint64_t=u_int64_t
.endif
