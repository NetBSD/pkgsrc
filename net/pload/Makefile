# $NetBSD: Makefile,v 1.34 2026/08/04 20:29:12 wiz Exp $
#

DISTNAME=	pload-0.9.5
PKGREVISION=	3
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/serial/ppp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20050305142516/http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	Network interface monitor for X11, monitoring totals and in/out rates
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	YES
USE_TOOLS+=	imake
INSTALL_TARGET=	install install.man

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
