# $NetBSD: options.mk,v 1.2 2024/07/03 19:18:39 cheusov Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellmpc
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	nls
.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=	gmake msgfmt
MAKE_FLAGS+=	enable_nls=1
PLIST.nls=	yes
post-install:
	${GMAKE} -C "${WRKSRC}/po" \
		${MAKE_FLAGS} \
		LOCALEDIR="${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale" \
		install
.endif
