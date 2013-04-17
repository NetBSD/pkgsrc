# $NetBSD: hacks.mk,v 1.1 2013/04/17 09:10:06 sbd Exp $

.if !defined(VIRTUOSO_HACKS_MK)
VIRTUOSO_HACKS_MK=	1

### [Wed Apr 17 19:21:24 NZST 2013 : sbd]
### Not all linux systems will have netstat(8), but if they don't then 
### they'll have ss(8) which does the same thing.
### (With out netstat the build stalls in an endless for loop.)
###
.if ${OPSYS} == "Linux"
post-tools:
	@if ! which netstat >/dev/null 2>/dev/null; then 		\
		${LN} -sf /sbin/ss ${TOOLS_DIR}/bin/netstat;		\
	fi
.endif

.endif # VIRTUOSO_HACKS_MK
