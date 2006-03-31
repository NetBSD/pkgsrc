# $NetBSD: options.mk,v 1.4 2006/03/31 18:35:22 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gauche
PKG_SUPPORTED_OPTIONS=	gdbm multibyte
PKG_SUGGESTED_OPTIONS=	gdbm multibyte

.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.prefs.mk"

###
### GDBM extension.  Modules seem to be better tested with GDBM
### than NDBM.
###
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
PLIST_SUBST+=	USE_GDBM=''
MAKE_ENV+=	GDBM_LDFLAGS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gdbm}/lib
.else
PLIST_SUBST+=	USE_GDBM='@comment '
.endif

###
### Multibyte extension.
###
.if !empty(PKG_OPTIONS:Mmultibyte) && defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE:Q}
.endif

.if defined(PKG_DEVELOPER)
.PHONY: print-multibyte-options
print-multibyte-options:
	${SED} -ne '/load "/ { s|^.*load "\([^"]*\)".*$|\1|; p; }' ${WRKSRC}/test/mb-chars.scm
.endif
