# $NetBSD: Makefile,v 1.26 2004/03/08 20:27:14 minskim Exp $
#

DISTNAME=	uudeview-0.5.18
PKGNAME=	xdeview-0.5.18
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	X11 program for uu/xx/Base64/BinHex de-/encoding

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${LOCALBASE}" --enable-tk="${LOCALBASE}"
LDFLAGS+=	-s -lX11
USE_BUILDLINK2=	yes

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../converters/uulib/buildlink2.mk"
.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
