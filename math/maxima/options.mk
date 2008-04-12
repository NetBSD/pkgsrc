# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:04 jlam Exp $

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
PLIST_VARS+=		${PKG_OPTIONS_GROUP.lisp}
.for opt in ${PKG_OPTIONS_GROUP.lisp}
.  if !empty(PKG_OPTIONS:M${opt})
PLIST.${opt}=		yes
.  endif
.endfor
