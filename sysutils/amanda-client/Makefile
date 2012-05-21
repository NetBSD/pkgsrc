# $NetBSD: Makefile,v 1.49 2012/05/21 04:27:09 sbd Exp $
#

PKGNAME=		amanda-client-${VERS}
PKGREVISION=		2
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk:run perl:run

PKG_SUPPORTED_OPTIONS+=		amanda-smb amanda-dump-snap

PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SMB:amanda-smb
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_DUMP_SNAP:amanda-dump-snap

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"
.include "../../sysutils/amanda-common/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"

CONFIGURE_ARGS+=	--without-server

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

.include "../../mk/bsd.pkg.mk"
