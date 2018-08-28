# $NetBSD: Makefile,v 1.15 2018/08/28 11:54:54 schmonz Exp $

DISTNAME=		xfractint-20.04p14
PKGNAME=		${DISTNAME:S/04p/4./}
CATEGORIES=		math
MASTER_SITES=		https://fractint.org/ftp/current/linux/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fractint.org/
COMMENT=		Fractint for X11

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

MAKE_FLAGS+=		BINDIR=${PREFIX}/bin
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=		SRCDIR=${PREFIX}/share/xfractint
BUILD_TARGET=		xfractint

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/xfractint/pars
INSTALLATION_DIRS+=	share/xfractint/formulas share/xfractint/ifs
INSTALLATION_DIRS+=	share/xfractint/lsystem share/xfractint/maps
INSTALLATION_DIRS+=	share/xfractint/extra

MAKE_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
