# $NetBSD: Makefile,v 1.48 2010/06/28 10:09:26 joerg Exp $
#

PKGNAME=		amanda-client-${VERS}
PKGREVISION=		2
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk:run perl:run

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"
.include "../../sysutils/amanda-common/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"

CONFIGURE_ARGS+=	--without-server

BUILD_DEFS+=		AMANDA_SMB AMANDA_DUMP_SNAP

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline. (XXX: incorrect, does not happen)
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba
.endif

.if defined(AMANDA_DUMP_SNAP)
CONFIGURE_ARGS+=	--with-dump-use-snapshot --with-rundump
.endif

.include "../../mk/bsd.pkg.mk"
