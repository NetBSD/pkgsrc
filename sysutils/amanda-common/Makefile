# $NetBSD: Makefile,v 1.30 2004/10/03 00:18:14 tv Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

PKGNAME=		amanda-common-${VERS}
PKGREVISION=		1
SVR4_PKGNAME=		amaco

COMMENT=		Common libraries and binaries for Amanda

USE_BUILDLINK3=		YES
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

PKG_GROUPS=		${AMANDA_GROUP}
PKG_USERS=		${AMANDA_USER}:${AMANDA_GROUP}::Amanda\\ user::${SH}

OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0700
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists  ${AMANDA_USER} ${AMANDA_GROUP} 0700

.include "../../mk/bsd.pkg.mk"
