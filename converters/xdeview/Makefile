# $NetBSD: Makefile,v 1.20 2001/12/26 11:12:53 tron Exp $
#

DISTNAME=	uudeview-0.5.15
PKGNAME=	xdeview-0.5.15
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	X11 program for uu/xx/Base64/BinHex de-/encoding

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	uulib-0.5.15:../../converters/uulib

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${LOCALBASE}" --enable-tk="${LOCALBASE}"
# Season to taste --- anything over tcl7.5
LDFLAGS+=	-s -lX11
CPPFLAGS+=	-I${LOCALBASE}/include

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
