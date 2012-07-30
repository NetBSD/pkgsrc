# $NetBSD: Makefile,v 1.52 2012/07/30 07:04:29 sbd Exp $

PKGNAME=		amanda-server-${AMANDA_VERSION}
PKGREVISION=		2
SVR4_PKGNAME=		amase

COMMENT=		Server part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/amanda-common/Makefile.common"

USE_TOOLS+=		awk:run perl:run mail:run

DEPENDS+=               p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

CONFIGURE_ENV+=		MAILER=${TOOLS_PATH.mail}
CONFIGURE_ARGS+=	--without-client --without-gnuplot

PLIST_VARS+=	scsi
.if ${OPSYS} != "SunOS"
PLIST.scsi=	yes
.endif

SPECIAL_PERMS+=		sbin/amcheck		${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/planner		${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/dumper		${AM_PROG_PERMS}

.include "../../sysutils/amanda-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
