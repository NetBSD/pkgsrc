# $NetBSD: Makefile,v 1.3 2001/01/25 15:57:25 jlam Exp $

DISTNAME=	xpp-0.7
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html

DEPENDS+=	cups>=1.1.1:../../print/cups
DEPENDS+=	fltk>=1.0.9:../../x11/fltk

USE_X11=	# defined

USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=	LIBS="${LIBS}"

CPPFLAGS+=	-I${LOCALBASE}/include		# cups/cups.h
LIBS+=		-lGL -lm			# -lfltk

DOCDIR=		${PREFIX}/share/doc/xpp

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
