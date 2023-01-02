# $NetBSD: Makefile,v 1.1 2023/01/02 22:43:52 vins Exp $

DISTNAME=	mgdiff
PKGNAME=	${DISTNAME}-1.0
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bsdforge.com/projects/textproc/mgdiff/
COMMENT=	Graphical front end to Unix diff
LICENSE=	mit

USE_IMAKE=	yes

LIBDIR=	lib/X11/${PKGBASE}

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	${LIBDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m ${DESTDIR}${PREFIX}/${LIBDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
