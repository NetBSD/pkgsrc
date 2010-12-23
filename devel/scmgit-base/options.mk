# $NetBSD: options.mk,v 1.4 2010/12/23 23:42:40 abs Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.scmgit
PKG_SUPPORTED_OPTIONS=	scmgit-gui python
PKG_SUGGESTED_OPTIONS=	scmgit-gui python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gui
PLIST_VARS+=		macosx
PLIST_VARS+=		python

.if !empty(PKG_OPTIONS:Mscmgit-gui)
PLIST.gui=		yes
USE_TOOLS+=		wish:run
CONFIGURE_ARGS+=	--with-tcltk=${WISH:Q}
.  if ${OPSYS} == "Darwin" && exists(/System/Library/Frameworks/Tk.framework)
.    if exists(/System/Library/Frameworks/Tk.framework/Resources/Wish.app)
WISH_APP=Wish
.    else
WISH_APP=Wish Shell
.    endif
PLIST_SUBST+= WISH_APP=${WISH_APP:Q}
PLIST.macosx=		yes
PRIVILEGED_STAGES+=	clean
.  endif
.else
CONFIGURE_ARGS+=	--without-tcltk
.endif

.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=	yes
MAKE_FLAGS+=	PYTHON_PATH=${PYTHONBIN}
PLIST.python=		yes
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--without-python
.endif
