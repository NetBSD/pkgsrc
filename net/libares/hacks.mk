# $NetBSD: hacks.mk,v 1.1 2005/03/12 05:42:48 tv Exp $

### [Sat Mar 12 05:35:46 UTC 2005 : tv]
### Need a real resolver on Interix.
###
.if ${OPSYS} == "Interix"
BUILDLINK_PASSTHRU_DIRS+= /usr/local/include/bind /usr/local/lib/bind
CPPFLAGS+=		-I/usr/local/include/bind
LDFLAGS+=		-L/usr/local/lib/bind
LIBS+=			-lbind -ldb
.endif
