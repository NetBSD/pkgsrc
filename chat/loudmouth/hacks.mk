# $NetBSD: hacks.mk,v 1.3 2019/11/02 22:18:23 rillig Exp $

.if !defined(HACKS_MK)
HACKS_MK=	defined

### [Tue Feb 21 19:10:18 NZDT 2012: sbd]
### 'AC_CHECK_LIB(resolv,res_query)' fails on Linux because the function's
### symbol name is '__res_query'.
###
.if "${OPSYS}" == "Linux"
PKG_HACKS+=	libresolv
LIBS+=		-lresolv
.endif

.endif
