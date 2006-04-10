# $NetBSD: hacks.mk,v 1.1 2006/04/10 13:26:15 schwarz Exp $

### [ Mon Apr 10 14:23:26 CDT 2006 : schwarz ]
### Define type to use for uint32_t on platforms that do not have it
### (cf. tnftp.h)
###
.if !empty(LOWER_OPSYS:Mirix5*)
PKG_HACKS+=	uint32_t
CPPFLAGS+=	-DUINT32_T=int
.endif
