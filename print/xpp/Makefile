# $NetBSD: Makefile,v 1.14 2001/10/23 13:15:02 jlam Exp $

DISTNAME=	xpp-1.0
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

DOCDIR=			${PREFIX}/share/doc/xpp

pre-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile.in aclocal.m4 configure

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/x11.buildlink.mk"
.include "../../print/cups/buildlink.mk"
.include "../../x11/fltk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
