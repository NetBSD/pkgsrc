# $NetBSD: Makefile,v 1.15 2003/05/02 11:56:06 wiz Exp $

DISTNAME=	kdenetwork-3.1.1
PKGREVISION=	1
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		yes
PTHREAD_OPTS+=		require

FOO_MAIN_FILES= \
	ksirc/ksirc_main.cpp \
	kxmlrpc/kxmlrpcd_main.cpp

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_sys_file_offset_bits=no
.endif

.include "../../x11/kde3/Makefile.foo_main"

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
