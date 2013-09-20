# $NetBSD: options.mk,v 1.8 2013/09/20 23:10:12 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hydra
PKG_SUPPORTED_OPTIONS=	gtk svn pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=	yes
.endif

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion-base/buildlink3.mk"
CONFIGURE_ENV+=	WITH_SVN=1
.else
CONFIGURE_ENV+=	WITH_SVN=0
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ENV+=	WITH_PGSQL=1
.else
CONFIGURE_ENV+=	WITH_PGSQL=0
.endif
