# $NetBSD: Makefile,v 1.8 2001/05/26 07:16:16 jlam Exp $

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

CPPFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

DOCDIR=		${PREFIX}/share/doc/xpp

pre-configure: ${BUILDLINK_TARGETS}
	cd ${WRKSRC}; ${TOUCH} Makefile.in aclocal.m4 configure

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
