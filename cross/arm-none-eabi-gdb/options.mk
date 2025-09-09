# $NetBSD: options.mk,v 1.1 2025/09/09 01:53:45 lloyd Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS+=	python
PKG_SUGGESTED_OPTIONS=	python

PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mpython}
PYTHON_VERSIONS_INCOMPATIBLE=	27
PLIST.python=			yes
CONFIGURE_ARGS+=		--with-python
PYTHON_FOR_BUILD_ONLY=		no
.include "../../lang/python/tool.mk"
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-python
.endif
