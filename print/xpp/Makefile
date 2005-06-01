# $NetBSD: Makefile,v 1.30 2005/06/01 18:03:20 jlam Exp $

DISTNAME=	xpp-1.1
PKGREVISION=	5
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

DOCDIR=		${PREFIX}/share/doc/xpp

.include "../../print/cups/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
