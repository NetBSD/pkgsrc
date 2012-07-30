# $NetBSD: Makefile,v 1.55 2012/07/30 07:03:04 sbd Exp $

PKGNAME=		amanda-common-${AMANDA_VERSION}
SVR4_PKGNAME=		amaco
PKGREVISION=		2

COMMENT=		Common libraries and binaries for Amanda

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/amanda-common/Makefile.common"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=		-D_LARGEFILE64_SOURCE
.endif

CONFIGURE_ARGS+=	--without-server --without-client --without-gnuplot

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

PKG_GROUPS=		${AMANDA_GROUP}
PKG_USERS=		${AMANDA_USER}:${AMANDA_GROUP}

PKG_GECOS.${AMANDA_USER}=	Amanda backup user
PKG_SHELL.${AMANDA_USER}=	${SH}
PKG_HOME.${AMANDA_USER}=	${AMANDA_VAR}

OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0750
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists ${AMANDA_USER} ${AMANDA_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/amanda ${AMANDA_USER} ${AMANDA_GROUP} 0750

INSTALL_MAKE_FLAGS+=	SETUID_GROUP=${ROOT_GROUP}

.include "../../mk/bsd.pkg.mk"
