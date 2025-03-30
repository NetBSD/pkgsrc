# $NetBSD: options.mk,v 1.7 2025/03/30 21:10:39 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4

PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.prefs.mk"

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
