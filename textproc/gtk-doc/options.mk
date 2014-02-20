# $NetBSD: options.mk,v 1.4 2014/02/20 09:43:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkdoc
PKG_SUPPORTED_OPTIONS=	sgml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msgml)
# XXX: will be removed after 1.20
DEPENDS+= dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
SGML_CATALOGS= ${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat
DEPENDS+= openjade-[0-9]*:../../textproc/openjade
.endif
