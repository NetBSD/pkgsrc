# $NetBSD: Makefile,v 1.8 2001/05/01 22:37:13 jtb Exp $

DISTNAME=		geomview-1.8.1
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=geomview/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.geomview.org
COMMENT=		Interactive geometry viewing program

CONFLICTS=		ImageMagick-*	# both have a program named 'animate'

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_MOTIF=		YES
USE_MESA=		YES

CONFIGURE_ARGS+=	--without-xforms
CONFIGURE_ARGS+=	--with-opengl=${X11BASE}
CONFIGURE_ARGS+=	--with-motif=${MOTIFBASE}
CONFIGURE_ENV+=		CPPFLAGS="-Dunix -Dalloca=__builtin_alloca"

INFO_FILES=		geomview

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/geomview.pdf			\
	${PREFIX}/share/doc/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/example*				\
	${PREFIX}/share/examples/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/geomview
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html 			\
	${PREFIX}/share/doc/html/geomview
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/geomview/pix
	${INSTALL_DATA} ${WRKSRC}/doc/html/pix/*			\
	${PREFIX}/share/doc/html/geomview/pix

.include "../../mk/bsd.pkg.mk"
