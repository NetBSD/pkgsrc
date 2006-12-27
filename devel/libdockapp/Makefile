# $NetBSD: Makefile,v 1.20 2006/12/27 13:37:36 joerg Exp $
#

DISTNAME=	libdockapp-0.4.0
PKGREVISION=	2
CATEGORIES=	devel wm
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/
COMMENT=	Simple library to create dockapps for WindowMaker

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libdockapp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libdockapp

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
