# $NetBSD: Makefile,v 1.32 2004/04/21 17:34:41 tron Exp $

DISTNAME=	kdenetwork-${_KDE_VERSION}
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

CONFLICTS=	kopete-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		yes
USE_DIRS+=		xdg-1.1
PTHREAD_OPTS+=		require

REPLACE_PERL=		ksirc/dsirc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_sys_file_offset_bits=no
.endif

.if !exists(${X11BASE}/lib/libXss.so)
CONFIGURE_ENV+=		ac_cv_lib_Xss_XScreenSaverQueryInfo="no"
.endif

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
