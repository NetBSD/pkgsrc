# $NetBSD: options.mk,v 1.1 2008/11/18 11:55:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkdoc
PKG_SUPPORTED_OPTIONS=	sgml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msgml)
DEPENDS+= dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
SGML_CATALOGS= ${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat
.include "../../textproc/jade/buildlink3.mk"
.endif
