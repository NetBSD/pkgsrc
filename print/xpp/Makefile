# $NetBSD: Makefile,v 1.12 2001/06/20 21:20:58 jlam Exp $

DISTNAME=	xpp-1.0
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_X11=		# defined
USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

DOCDIR=			${PREFIX}/share/doc/xpp

pre-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile.in aclocal.m4 configure

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../print/cups/buildlink.mk"
.include "../../x11/fltk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
