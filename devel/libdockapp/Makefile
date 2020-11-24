# $NetBSD: Makefile,v 1.27 2020/11/24 11:13:25 nia Exp $

DISTNAME=	libdockapp-0.7.3
CATEGORIES=	devel wm
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/libdockapp
COMMENT=	Simple library to create dockapps for WindowMaker
LICENSE=	mit

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/fonts/X11/misc/fonts.dir

FONTS_DIRS.x11=		share/fonts/X11/misc

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
