# $NetBSD: Makefile,v 1.30 2002/10/25 18:52:44 wiz Exp $
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-client-2.4.2p2
SVR4_PKGNAME=		amacl
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Client part of Amanda, a network backup system

DEPENDS+=		amanda-common-2.4.2p2:../../sysutils/amanda-common

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"
.include "../../sysutils/amanda-common/buildlink2.mk"
#.include "../../devel/readline/buildlink2.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		{gtar,gtar-base}>=1.12:../../archivers/gtar-base
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
