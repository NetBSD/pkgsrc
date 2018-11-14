# $NetBSD: Makefile,v 1.65 2018/11/14 22:22:20 kleink Exp $

DISTNAME=	xpp-1.5
PKGREVISION=	25
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CFLAGS+=	-D_IPP_PRIVATE_STRUCTURES

DOCDIR=		${PREFIX}/share/doc/xpp

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE README ${DESTDIR}${DOCDIR}

.include "../../print/cups-base/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
