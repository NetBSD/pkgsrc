# $NetBSD: options.mk,v 1.1 2021/05/07 07:08:39 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.editline
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS+=	# empty; conflicts with devel/readline

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc
.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
.else
.  if empty(PKG_OPTIONS:Mdoc)
editline-remove-docs:
	${ECHO} "" > ${WRKSRC}/doc/Makefile.am

post-extract: editline-remove-docs
.  endif
.endif
