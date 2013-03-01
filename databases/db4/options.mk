# $NetBSD: options.mk,v 1.5 2013/03/01 16:10:23 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4

PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc

PLIST_SRC+=		PLIST

.include "../../mk/bsd.options.mk"

###
### Install documentation files
###
.if empty(PKG_OPTIONS:Mdoc)
SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	dist/Makefile.in
SUBST_SED.docs=		-e '/^library_install:/s, install_docs,,'
.else
PLIST_SRC+=		PLIST.docs
.endif
