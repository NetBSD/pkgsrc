# $NetBSD: options.mk,v 1.3 2013/10/31 09:05:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkdoc
PKG_SUPPORTED_OPTIONS=	sgml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msgml)
DEPENDS+= dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
SGML_CATALOGS= ${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat
DEPENDS+= openjade-[0-9]*:../../textproc/openjade
.endif
