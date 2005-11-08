# $NetBSD: hacks.mk,v 1.1 2005/11/08 14:05:23 tv Exp $

###
### Need a real resolver on Interix.
###
.if ${OPSYS} == "Interix"
BUILDLINK_PASSTHRU_DIRS+= /usr/local/include/bind /usr/local/lib/bind
CPPFLAGS+=		-I/usr/local/include/bind
LDFLAGS+=		-L/usr/local/lib/bind
LIBS+=			-lbind -ldb
.endif
