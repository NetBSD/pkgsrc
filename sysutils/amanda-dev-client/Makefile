# $NetBSD: Makefile,v 1.4 2002/10/25 18:59:46 wiz Exp $
#

PKGNAME=		amanda-client-${VERS}
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

DEPENDS+=		amanda-common-${VERS}:../../sysutils/amanda-dev-common

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"
.include "../../sysutils/amanda-dev-common/buildlink2.mk"
#.include "../../devel/readline/buildlink2.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		{gtar,gtar-base}>=1.12:../../archivers/gtar
.endif

CONFIGURE_ARGS+=	--without-server --without-restore

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline. (XXX: incorrect, does not happen)
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
