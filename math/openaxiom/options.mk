# $NetBSD: options.mk,v 1.1.1.1 2008/08/28 20:07:51 ahoka Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openaxiom
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl ecl

PKG_SUPPORTED_OPTIONS+=		x11

PKG_SUGGESTED_OPTIONS+=		clisp x11

.include "../../mk/bsd.options.mk"

# Select Lisp backend
.if !empty(PKG_OPTIONS:Mclisp)
FASL=			fas
DEPENDS+=		clisp>=2.41:../../lang/clisp
CONFIGURE_ARGS+=	--with-lisp=clisp
.endif
.if !empty(PKG_OPTIONS:Msbcl)
FASL=			fasl
DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
CONFIGURE_ARGS+=	--with-lisp=sbcl
.endif
.if !empty(PKG_OPTIONS:Mecl)
FASL=			fas
CONFIGURE_ARGS+=	--with-lisp=ecl
.include "../../lang/ecl/buildlink3.mk"
.endif

# Fix suffix for "fast load" files:
PLIST_SUBST+=	FASL=${FASL:Q}

# Generalize "fast load" files
PRINT_PLIST_AWK+=	{gsub(/\.${FASL}$$/, ".$${FASL}");}
.if !empty(PKG_OPTIONS:Mclisp)
# Handle CLISP-specific files
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.lib$$/) {$$0 = "$${clisp}" $$0;}}
.endif
.if !empty(PKG_OPTIONS:Mecl)
# Handle ECL-specific files
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.o$$/) {$$0 = "$${ecl}" $$0;}}
.endif

# X11
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

.for opt in clisp sbcl ecl x11
.  if !empty(PKG_OPTIONS:M${opt})
PLIST_SUBST+=	${opt}=""
.  else
PLIST_SUBST+=	${opt}="@comment "
.  endif
.endfor
