# $NetBSD: Makefile,v 1.35 2005/12/05 20:49:56 rillig Exp $

DISTNAME=	uudeview-0.5.20
PKGNAME=	xdeview-0.5.20
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	X11 program for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-tcl=${LOCALBASE:Q}
CONFIGURE_ARGS+=	--enable-tk=${LOCALBASE:Q}
LDFLAGS+=	-s -lX11

BUILD_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../converters/uulib/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
