# $NetBSD: Makefile,v 1.53 2012/07/30 07:00:50 sbd Exp $
#

PKGNAME=		amanda-client-${AMANDA_VERSION}
PKGREVISION=		2
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=		awk:run perl:run

.include "../../sysutils/amanda-common/Makefile.common"
CONFIGURE_ARGS+=	--without-server --without-gnuplot

.if !empty(PKG_OPTIONS:Mamanda-smb)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba
.endif

.if !empty(PKG_OPTIONS:Mamanda-dump-snap)
CONFIGURE_ARGS+=	--with-dump-use-snapshot --with-rundump
.endif

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline. (XXX: incorrect, does not happen)
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

.include "../../sysutils/amanda-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
