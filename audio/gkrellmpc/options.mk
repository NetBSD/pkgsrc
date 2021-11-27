# $NetBSD: options.mk,v 1.1 2021/11/27 10:37:24 pho Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellmpc
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=	gmake msgfmt
MAKE_FLAGS+=	enable_nls=1
post-install:
	${GMAKE} -C "${WRKSRC}/po" \
		${MAKE_FLAGS} \
		LOCALEDIR="${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale" \
		install
.endif
