# $NetBSD: options.mk,v 1.3 2016/08/02 16:56:32 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeDiameter
PKG_SUPPORTED_OPTIONS=	freediameter-all-extensions
PKG_SUGGESTED_OPTIONS=	freediameter-all-extensions

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ext

.if !empty(PKG_OPTIONS:Mfreediameter-all-extensions)
# enable all except debugging and test
#CMAKE_ARGS+=	-DALL_EXTENSIONS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_APP_ACCT:BOOL=ON
CMAKE_ARGS+=	-DBUILD_APP_DIAMEAP:BOOL=ON
CMAKE_ARGS+=	-DBUILD_APP_RADGW:BOOL=ON
CMAKE_ARGS+=	-DBUILD_APP_REDIRECT:BOOL=ON
CMAKE_ARGS+=	-DBUILD_APP_SIP:BOOL=ON
CMAKE_ARGS+=	-DBUILD_DICT_LEGACY_XML:BOOL=ON
CMAKE_ARGS+=	-DBUILD_RT_EREG:BOOL=ON
# for debug-interactive-extension only
#.include "../../devel/swig/buildlink3.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
PLIST.ext=	yes
.else
CMAKE_ARGS+=	-DALL_EXTENSIONS:BOOL=OFF
.endif
