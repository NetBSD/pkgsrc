# $NetBSD: Makefile,v 1.16.2.1 2002/07/01 17:45:07 jlam Exp $

DISTNAME=	xpp-1.0
PKGREVISION=	1
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_BUILDLINK2=	# defined
USE_X11=	# defined
USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/xpp

pre-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile.in aclocal.m4 configure

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../print/cups/buildlink2.mk"
.include "../../x11/fltk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
