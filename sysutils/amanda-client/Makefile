# $NetBSD: Makefile,v 1.26 2001/12/25 20:50:00 wiz Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-client-2.4.2p2
SVR4_PKGNAME=		amacl
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Client part of Amanda, a network backup system

DEPENDS+=		gtar-1.12:../../archivers/gtar
DEPENDS+=		amanda-common-2.4.2p2:../../sysutils/amanda-common

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"
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
DEPENDS+=		samba>=2.0.0:../../net/samba
.endif

.include "../../mk/bsd.pkg.mk"
