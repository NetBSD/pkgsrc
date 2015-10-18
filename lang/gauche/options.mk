# $NetBSD: options.mk,v 1.9 2015/10/18 00:54:19 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gauche
PKG_OPTIONS_OPTIONAL_GROUPS=	multibyte
PKG_OPTIONS_GROUP.multibyte=	utf8 eucjp sjis
PKG_SUPPORTED_OPTIONS=		gdbm
PKG_SUGGESTED_OPTIONS=		gdbm utf8
PKG_OPTIONS_LEGACY_VARS+=	GAUCHE_MULTIBYTE:utf8
PKG_OPTIONS_LEGACY_OPTS+=	multibyte:utf8

.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.prefs.mk"

###
### GDBM extension.  Modules seem to be better tested with GDBM
### than NDBM.
###
PLIST_VARS+=	gdbm
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
PLIST.gdbm=	yes
GDBM_LDFLAGS=	-L${BUILDLINK_PREFIX.gdbm}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gdbm}/lib
MAKE_ENV+=	GDBM_LDFLAGS=${GDBM_LDFLAGS:Q}
.endif

###
### Multibyte extension.
###
.for encoding in utf8 eucjp sjis
.  if !empty(PKG_OPTIONS:M${encoding})
CONFIGURE_ARGS+=	--enable-multibyte=${encoding}
.  endif
.endfor

.if defined(PKG_DEVELOPER)
.PHONY: print-multibyte-options
print-multibyte-options:
	${SED} -ne '/load "/ { s,^.*load "\([^"]*\)".*$$,\1,; p; }' ${WRKSRC}/test/mb-chars.scm
.endif
