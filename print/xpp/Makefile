# $NetBSD: Makefile,v 1.4 2001/01/30 16:37:55 jlam Exp $

DISTNAME=	xpp-1.0
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
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
	cd ${WRKSRC} && autoconf && touch aclocal.m4 Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} LICENSE README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
