# $NetBSD: Makefile,v 1.25 2012/10/31 11:17:12 asau Exp $
#

DISTNAME=	libdockapp-0.6.2
CATEGORIES=	devel wm
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/
COMMENT=	Simple library to create dockapps for WindowMaker

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

INSTALLATION_DIRS=	share/doc/libdockapp

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/libdockapp

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
