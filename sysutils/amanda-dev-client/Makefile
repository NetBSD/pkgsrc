# $NetBSD: Makefile,v 1.2.6.1 2002/12/22 08:52:33 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

PKGNAME=		amanda-client-${VERS}
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

DEPENDS+=		{gtar,gtar-base}>=1.12:../../archivers/gtar-base
DEPENDS+=		amanda-common-${VERS}:../../sysutils/amanda-dev-common

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"
.include "../../devel/readline/buildlink.mk"

CONFIGURE_ARGS+=	--without-server --without-restore

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline.
#
CONFIGURE_ENV+=         ac_cv_lib_intl_main=no
CONFIGURE_ENV+=         ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_readline_readline=no

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba
.endif

.include "../../mk/bsd.pkg.mk"
