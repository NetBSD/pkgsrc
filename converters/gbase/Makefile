# $NetBSD: Makefile,v 1.38 2026/09/02 19:01:14 wiz Exp $

DISTNAME=	gbase-0.5
PKGREVISION=	33
CATEGORIES=	converters math
#MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://fluxcode.net/projects/gbase-2
COMMENT=	GTK program designed to convert between the four common bases
LICENSE=	artistic

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin

BUILD_TARGET=	gbase

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbase ${DESTDIR}${PREFIX}/bin/gbase

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
