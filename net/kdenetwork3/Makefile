# $NetBSD: Makefile,v 1.35 2004/10/03 00:17:53 tv Exp $

DISTNAME=	kdenetwork-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

CONFLICTS=	kopete-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
PTHREAD_OPTS+=		require

REPLACE_PERL=		ksirc/dsirc \
			knewsticker/knt-0.1-0.2.pl \
			kopete/kopete/kconf_update/kopete-pluginloader.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_sys_file_offset_bits=no
.endif

.if !exists(${X11BASE}/lib/libXss.so)
CONFIGURE_ENV+=		ac_cv_lib_Xss_XScreenSaverQueryInfo="no"
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
