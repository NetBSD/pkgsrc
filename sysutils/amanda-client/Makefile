# $NetBSD: Makefile,v 1.21 2001/06/11 02:05:15 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2
PKGNAME=		amanda-client-2.4.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Client part of Amanda, a network backup system

DEPENDS+=		gtar-1.12:../../archivers/gtar
DEPENDS+=		amanda-common-2.4.2:../../sysutils/amanda-common

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"
.include "../../devel/readline/buildlink.mk"

CONFIGURE_ARGS+=	--without-server --without-restore
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline.
#
CONFIGURE_ENV+=         ac_cv_lib_intl_main=no
CONFIGURE_ENV+=         ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_readline_readline=no

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

.if defined(AMANDA_SMB)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		samba>=2.0.0:../../net/samba
.endif

.include "../../mk/bsd.pkg.mk"
