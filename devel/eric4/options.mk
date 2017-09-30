# $NetBSD: options.mk,v 1.5 2017/09/30 13:59:12 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eric4
PKG_SUPPORTED_OPTIONS=	sqlite mysql pgsql enchant pylint cxfreeze rope
PKG_SUGGESTED_OPTIONS=	sqlite


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		qt4-sqlite3>=4.6.2:../../x11/qt4-sqlite3
.endif

#Enable support for mysql & postgresql | build Qt4-drivers
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=		qt4-mysql>=4.6.2:../../x11/qt4-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=		qt4-pgsql>=4.6.2:../../x11/qt4-pgsql
.endif

#Enable spell-checking
.if !empty(PKG_OPTIONS:Menchant)
DEPENDS+=		${PYPKGPREFIX}-enchant>=1.4.2:../../textproc/py-enchant
.endif

#Enable source code analyzer for python
.if !empty(PKG_OPTIONS:Mpylint)
DEPENDS+=		${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
.endif

#Enable support for freezing Python scripts
.if !empty(PKG_OPTIONS:Mcxfreeze)
DEPENDS+=		${PYPKGPREFIX}-cxfreeze-[0-9]*:../../lang/py-cxfreeze
.endif

#Enable support for code refactoring
.if !empty(PKG_OPTIONS:Mrope)
DEPENDS+=		${PYPKGPREFIX}-rope-[0-9]*:../../devel/py-rope
.endif
