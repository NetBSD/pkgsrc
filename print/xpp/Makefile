# $NetBSD: Makefile,v 1.20 2004/01/03 18:49:52 reed Exp $

DISTNAME=	xpp-1.1
PKGREVISION=	2
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_BUILDLINK2=	# defined
USE_X11=	# defined
USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/xpp

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../print/cups/buildlink2.mk"
.include "../../x11/fltk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
