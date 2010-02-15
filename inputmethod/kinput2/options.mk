# $NetBSD: options.mk,v 1.2 2010/02/15 13:41:17 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kinput2
PKG_OPTIONS_NONEMPTY_SETS=	inputmethod
PKG_OPTIONS_SET.inputmethod=	canna wnn4 sj3
PKG_SUGGESTED_OPTIONS=	canna wnn4 sj3
#PKG_OPTIONS_SET.inputmethod+=	wnn6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
KINPUT2_DEFS+=	-DUseCanna
KINPUT2_DEFS+=	-Dport_CANNASRC=${BUILDLINK_PREFIX.Canna-lib}/include
KINPUT2_DEFS+=	-Dport_CANNALIB="${LDFLAGS} -lcanna16"
.endif

#.if !empty(PKG_OPTIONS:Mwnn6)
#DEPENDS+=
#KINPUT2_DEFS+=	-DUseWnn -DUseWnn6 -Dport_WNNINCDIR=${LOCALBASE}/include/wnn \
#		-Dport_WNNLIB="${LDFLAGS} -lwnn6 -lcrypt"
#.elif !empty(PKG_OPTIONS:Mwnn4)
.if !empty(PKG_OPTIONS:Mwnn4)
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
KINPUT2_DEFS+=	-DUseWnn
KINPUT2_DEFS+=	-Dport_WNNINCDIR=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/include/wnn
KINPUT2_DEFS+=	-Dport_WNNLIB="${LDFLAGS} -lwnn -lcrypt"
PLIST_SRC+=	${PKGDIR}/PLIST-freewnn
.endif

.if !empty(PKG_OPTIONS:Msj3)
.include "../../inputmethod/sj3-client/buildlink3.mk"
KINPUT2_DEFS+=	-DUseSj3
KINPUT2_DEFS+=	-Dport_SJ3SRC=${BUILDLINK_PREFIX.sj3-lib}/include
KINPUT2_DEFS+=	-Dport_SJ3LIB="${LDFLAGS} -lsj3lib"
PLIST_SRC+=	${PKGDIR}/PLIST-sj3
.endif
