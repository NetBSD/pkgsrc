# $NetBSD: pkginstall.mk,v 1.2 2005/12/29 13:47:43 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and determines whether
# or not the bsd.pkginstall.mk implementation file should be included.
#
# _PKGINSTALL_VARS is a list of the variables that, if non-empty, indicate
#	that the pkginstall framework should be used.  These variables
#	should be extracted from bsd.pkginstall.mk and are typically the
#	variables named in the INSTALL_<SCRIPT>_MEMBERS lists.
#
# The variables listed in _PKGINSTALL_VARS are documented in
# mk/install/bsd.pkginstall.mk.
#
_PKGINSTALL_VARS+=	HEADER_EXTRA_TMPL
_PKGINSTALL_VARS+=	DEINSTALL_PRE_TMPL DEINSTALL_EXTRA_TMPL		\
			DEINSTALL_TMPL
_PKGINSTALL_VARS+=	INSTALL_TMPL INSTALL_EXTRA_TMPL			\
			INSTALL_POST_TMPL INSTALL_UNPACK_TMPL
_PKGINSTALL_VARS+=	DEINSTALL_SRC INSTALL_SRC

_PKGINSTALL_VARS+=	PKG_GROUPS PKG_USERS
_PKGINSTALL_VARS+=	SPECIAL_PERMS
_PKGINSTALL_VARS+=	CONF_FILES CONF_FILES_PERMS			\
			REQD_FILES REQD_FILES_PERMS			\
			RCD_SCRIPTS
_PKGINSTALL_VARS+=	MAKE_DIRS MAKE_DIRS_PERMS			\
			REQD_DIRS REQD_DIRS_PERMS			\
			OWN_DIRS OWN_DIRS_PERMS
_PKGINSTALL_VARS+=	PKG_SHELL
_PKGINSTALL_VARS+=	FONTS_DIRS.ttf FONTS_DIRS.type1 FONTS_DIRS.x11

# CONF_DEPENDS notes a dependency where the config directory for the
# package matches the dependency's config directory.  CONF_DEPENDS is
# only meaningful if PKG_INSTALLATION_TYPE is "pkgviews".
#
_PKGINSTALL_VARS+=	CONF_DEPENDS

_USE_PKGINSTALL=	no
.for _var_ in ${_PKGINSTALL_VARS}
.  if defined(${_var_}) && !empty(${_var_}:M*)
_USE_PKGINSTALL=	yes
.  endif
.endfor

.if !empty(_USE_PKGINSTALL:M[yY][eE][sS])
.  include "../../mk/install/bsd.pkginstall.mk"
.endif
