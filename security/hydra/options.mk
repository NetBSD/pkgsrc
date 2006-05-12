# $NetBSD: options.mk,v 1.1 2006/05/12 23:35:55 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hydra
PKG_SUPPORTED_OPTIONS=	gtkfe svn pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkfe)
.include "../../x11/gtk2/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/hydra-gtk && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC}/hydra-gtk && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin
PLIST_SRC+=	${PKGDIR}/PLIST.xhydra
.endif

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql81-client/buildlink3.mk"
.endif
