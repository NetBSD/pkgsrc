# $NetBSD: Makefile,v 1.19 2003/07/17 22:52:48 grant Exp $

DISTNAME=	xpp-1.1
PKGREVISION=	1
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
