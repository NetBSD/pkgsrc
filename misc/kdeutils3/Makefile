# $NetBSD: Makefile,v 1.5 2002/10/02 04:46:46 markd Exp $

DISTNAME=	kdeutils-3.0.3
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
