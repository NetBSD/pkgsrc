# $NetBSD: Makefile,v 1.19 2001/11/20 07:00:13 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-common-2.4.2p2
SVR4_PKGNAME=		amaco
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Libraries and binaries used by both the client and server parts of amanda

USE_BUILDLINK_ONLY=	YES

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
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

PKG_USER=		${AMANDA_USER}
PKG_USER_DESCR=		Amanda user
PKG_USER_SHELL=		${SH}
PKG_GROUP=		${AMANDA_GROUP}

OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0700
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists  ${AMANDA_USER} ${AMANDA_GROUP} 0700

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
