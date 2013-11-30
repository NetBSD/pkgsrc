# $NetBSD: options.mk,v 1.6 2013/11/30 16:25:12 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4

PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "MirBSD"
PLIST_SRC+=		PLIST.${OPSYS}
.else
PLIST_SRC+=		PLIST
.endif

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
