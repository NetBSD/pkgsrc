# $NetBSD: options.mk,v 1.5 2007/01/19 12:59:01 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gauche
PKG_OPTIONS_OPTIONAL_GROUPS=	multibyte
PKG_OPTIONS_GROUP.multibyte=	utf8 eucjp sjis
PKG_SUPPORTED_OPTIONS=	gdbm
PKG_SUGGESTED_OPTIONS=	gdbm utf8

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
.for __encoding in utf8 eucjp sjis
.if !empty(PKG_OPTIONS:M${__encoding})
CONFIGURE_ARGS+=	--enable-multibyte=${__encoding}
.endif
.endfor

.if defined(PKG_DEVELOPER)
.PHONY: print-multibyte-options
print-multibyte-options:
	${SED} -ne '/load "/ { s|^.*load "\([^"]*\)".*$|\1|; p; }' ${WRKSRC}/test/mb-chars.scm
.endif
