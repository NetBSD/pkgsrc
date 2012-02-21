# $NetBSD: hacks.mk,v 1.1 2012/02/21 06:27:38 sbd Exp $

.if !defined(HACKS_MK)
HACKS_MK= defined

### [Tue Feb 21 19:10:18 NZDT 2012: sbd]
### 'AC_CHECK_LIB(resolv,res_query)' fails on Linux because the function's
### symbol name is '__res_query'.
###
.if "${OPSYS}" == "Linux"
PKG_HACKS+=     libresolv
LIBS+=          -lresolv
.endif

.endif
