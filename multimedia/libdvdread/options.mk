# $NetBSD: options.mk,v 1.1 2013/05/10 07:13:59 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdvdread
PKG_SUPPORTED_OPTIONS=	dvdcss

.if !empty(PKG_OPTIONS:Mdvdcss)
CPPFLAGS+=		-DHAVE_DVDCSS_DVDCSS_H=1
LIBS+=			-ldvdcss
.include "../../multimedia/libdvdcss/buildlink3.mk"
.endif
