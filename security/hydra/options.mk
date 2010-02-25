# $NetBSD: options.mk,v 1.6 2010/02/25 17:55:48 joerg Exp $

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
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${DESTDIR}${PREFIX}/bin
PLIST_SRC+=	${PKGDIR}/PLIST.xhydra
.endif

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion-base/buildlink3.mk"
CONFIGURE_ENV+=	WITH_SVN=1
.else
CONFIGURE_ENV+=	WITH_SVN=0
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql82-client/buildlink3.mk"
CONFIGURE_ENV+=	WITH_PGSQL=1
.else
CONFIGURE_ENV+=	WITH_PGSQL=0
.endif
