# $NetBSD: Makefile,v 1.6 2001/02/17 17:51:58 wiz Exp $

DISTNAME=	xpp-1.0
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=	cups>=1.1.1:../../print/cups
DEPENDS+=	fltk>=1.0.9:../../x11/fltk

USE_X11=	# defined

USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

EVAL_PREFIX+=	FLTKDIR=fltk
CPPFLAGS+=	-I${FLTKDIR}/include		# FL/Fl.h
CPPFLAGS+=	-I${LOCALBASE}/include		# cups/cups.h

DOCDIR=		${PREFIX}/share/doc/xpp

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && touch aclocal.m4 Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
