# $NetBSD: Makefile,v 1.10 2001/06/11 02:05:14 jlam Exp $

DISTNAME=	xpp-1.0
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_X11=	# defined

USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../print/cups/buildlink.mk"
.include "../../x11/fltk/buildlink.mk"

DOCDIR=		${PREFIX}/share/doc/xpp

pre-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile.in aclocal.m4 configure

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
