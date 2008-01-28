# $NetBSD: options.mk,v 1.1 2008/01/28 12:08:49 reinoud Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.maxima
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl

PKG_SUGGESTED_OPTIONS+=		clisp

.include "../../mk/bsd.options.mk"

# Select Lisp backend
.if !empty(PKG_OPTIONS:Mclisp)
DEPENDS+=		clisp-[0-9]*:../../lang/clisp
CONFIGURE_ARGS+=	--enable-clisp
.endif
.if !empty(PKG_OPTIONS:Msbcl)
DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
CONFIGURE_ARGS+=	--enable-sbcl
.endif

# Modify PLIST
.for opt in clisp sbcl
.if !empty(PKG_OPTIONS:M${opt})
PLIST_SUBST+=	${opt}=""
.else
PLIST_SUBST+=	${opt}="@comment "
.endif
.endfor
