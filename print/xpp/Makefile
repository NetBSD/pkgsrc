# $NetBSD: Makefile,v 1.26 2004/06/27 13:28:01 grant Exp $

DISTNAME=	xpp-1.1
PKGREVISION=	4
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

DOCDIR=		${PREFIX}/share/doc/xpp

.include "../../print/cups/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
