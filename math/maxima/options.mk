# $NetBSD: options.mk,v 1.4 2010/08/26 10:21:12 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.maxima
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl ecl

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
.if !empty(PKG_OPTIONS:Mecl)
DEPENDS+=		ecl-[0-9]*:../../lang/ecl
CONFIGURE_ARGS+=	--enable-ecl
.include "../../lang/ecl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif

# Modify PLIST
PLIST_VARS+=		${PKG_OPTIONS_GROUP.lisp}
.for opt in ${PKG_OPTIONS_GROUP.lisp}
.  if !empty(PKG_OPTIONS:M${opt})
PLIST.${opt}=		yes
.  endif
.endfor
