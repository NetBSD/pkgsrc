# $NetBSD: options.mk,v 1.2 2013/05/12 03:04:26 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdvdread
PKG_SUPPORTED_OPTIONS=	dvdcss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdvdcss)
CPPFLAGS+=		-DHAVE_DVDCSS_DVDCSS_H=1
LIBS+=			-ldvdcss
.include "../../multimedia/libdvdcss/buildlink3.mk"
.endif
