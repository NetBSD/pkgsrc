# $NetBSD: Makefile,v 1.50 2023/11/12 13:20:53 wiz Exp $

DISTNAME=	uudeview-0.5.20
PKGNAME=	xdeview-0.5.20
PKGREVISION=	11
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	X11 program for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-tcl=${LOCALBASE:Q}
CONFIGURE_ARGS+=	--enable-tk=${LOCALBASE:Q}
LDFLAGS+=		-s -lX11

BUILD_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/uulib/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
