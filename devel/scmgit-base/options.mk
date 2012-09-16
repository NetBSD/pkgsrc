# $NetBSD: options.mk,v 1.6 2012/09/16 21:50:16 cheusov Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.scmgit
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		python

.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=	yes
MAKE_FLAGS+=	PYTHON_PATH=${PYTHONBIN}
PLIST.python=		yes
# not executable
CHECK_INTERPRETER_SKIP+= ${PYSITELIB}/git_remote_helpers/*.py
CHECK_INTERPRETER_SKIP+= ${PYSITELIB}/git_remote_helpers/git/*.py
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--without-python
.endif
