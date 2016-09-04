# $NetBSD: options.mk,v 1.3 2016/09/04 16:54:13 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rrdtool
PKG_SUPPORTED_OPTIONS=	lua python tcl
PKG_SUGGESTED_OPTIONS=	lua python tcl

# Note that there's another (apparently different) python library
# in databases/py-python-rrdtool.

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		python tcl lua


#
# XXX: this should include egg.mk, but that doesn't work: it includes
# extension.mk, which sets do-build and do-install rules, in such a
# way that we can't override it. Instead we need to cutpaste the
# definition of EGG_INFODIR and its plist bits. Sigh. Probably the
# right thing to do is make this a separate package.
#
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--enable-python

REPLACE_PYTHON=		examples/stripes.py
.include "../../lang/python/application.mk"

PLIST.python=		yes
EGG_NAME=		py_rrdtool-0.2.2
EGG_INFODIR?=		${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PLIST_SUBST+=		EGG_INFODIR=${EGG_INFODIR}
DEPENDS+=       ${PYPKGPREFIX}-setuptools>=0.8:../../devel/py-setuptools
#.include "../../lang/python/egg.mk"

.else # python
CONFIGURE_ARGS+=	--disable-python
.endif


.if !empty(PKG_OPTIONS:Mtcl)
USE_TOOLS+=		tclsh:run
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--with-tcllib=${BUILDLINK_PREFIX.tcl}/lib

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh@TCL_VERSION@
REPLACE.tclsh.new=	${BUILDLINK_PREFIX.tcl}/bin/tclsh
REPLACE_FILES.tclsh=	bindings/tcl/ifOctets.tcl.in

PLIST.tcl=		yes
.include "../../lang/tcl/buildlink3.mk"

.else # tcl
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ENV+=		ac_cv_path_LUA=${LUA_INTERPRETER}
PLIST.lua=		yes
.include "../../lang/lua/module.mk"
.else
CONFIGURE_ARGS+=	--disable-lua
.endif
