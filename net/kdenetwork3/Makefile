# $NetBSD: Makefile,v 1.21 2003/09/17 23:28:28 markd Exp $

DISTNAME=	kdenetwork-3.1.4
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		yes
PTHREAD_OPTS+=		require

FOO_MAIN_FILES= \
	ksirc/ksirc_main.cpp \
	kxmlrpc/kxmlrpcd_main.cpp

REPLACE_PERL=		ksirc/dsirc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_sys_file_offset_bits=no
.endif

.include "../../meta-pkgs/kde3/Makefile.foo_main"

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
