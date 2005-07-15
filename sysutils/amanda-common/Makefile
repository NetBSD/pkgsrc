# $NetBSD: Makefile,v 1.34 2005/07/15 22:19:11 kristerw Exp $

PKGNAME=		amanda-common-${VERS}
PKGREVISION=		1
SVR4_PKGNAME=		amaco

COMMENT=		Common libraries and binaries for Amanda

USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

.if ${OPSYS} == "NetBSD"
CPPFLAGS=		# empty
.elif ${OPSYS} == "SunOS"
CPPFLAGS+=		-D_LARGEFILE64_SOURCE
.endif

CONFIGURE_ARGS+=	--without-server --without-restore --without-client

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

CONFIGURE_ENV+=		GNUTAR=${TOOLS_TAR}
USE_TOOLS+=		tar

PKG_GROUPS=		${AMANDA_GROUP}
PKG_USERS=		${AMANDA_USER}:${AMANDA_GROUP}::Amanda\\ user::${SH}

OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0700
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists  ${AMANDA_USER} ${AMANDA_GROUP} 0700

.include "../../mk/bsd.pkg.mk"
