# $NetBSD: Makefile,v 1.26 2003/12/08 14:41:40 wiz Exp $

DISTNAME=	kdeutils-3.1.4
COMMENT=	Utilities for the KDE integrated X11 desktop
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

FOO_MAIN_FILES= \
	kcalc/kcalc_main.cpp \
	kedit/kedit_main.cpp \
	klaptopdaemon/klaptopdaemon_main.cpp

.include "../../meta-pkgs/kde3/Makefile.foo_main"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
