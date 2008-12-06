# $NetBSD: Makefile,v 1.1.1.1 2008/12/06 12:56:27 obache Exp $

DISTNAME=	xhomer-9-16-06
PKGNAME=	xhomer-9.16.06
CATEGORIES=	emulators
MASTER_SITES=	http://xhomer.isani.org/xhomer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmaier@happymolars.org
HOMEPAGE=	http://xhomer.isani.org/xhomer/
COMMENT=	DEC Pro 350/380 emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

BUILD_TARGET=	xhomer

MAKE_FLAGS+=	X11DIR=${X11BASE} USE_DGA2=Y USE_DGA1=N

INSTALLATION_DIRS=	bin share/examples/xhomer share/doc/xhomer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xhomer ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bat.ram ${DESTDIR}${PREFIX}/share/examples/xhomer
	${INSTALL_DATA} ${WRKSRC}/xhomer.cfg ${DESTDIR}${PREFIX}/share/examples/xhomer/
	${INSTALL_DATA} ${WRKSRC}/DOC/*  ${DESTDIR}${PREFIX}/share/doc/xhomer

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
