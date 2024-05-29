# $NetBSD: Makefile,v 1.90 2024/05/29 16:34:12 adam Exp $

DISTNAME=	xpp-1.5
PKGREVISION=	46
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CFLAGS+=	-D_IPP_PRIVATE_STRUCTURES

# mainwindow.h must be generated before compilation of mainwindow.c
MAKE_JOBS_SAFE=	no

DOCDIR=		${PREFIX}/share/doc/xpp

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE README ${DESTDIR}${DOCDIR}

.include "../../print/cups-base/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
