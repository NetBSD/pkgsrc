# $NetBSD: Makefile,v 1.12 2001/02/16 15:22:18 wiz Exp $
#

DISTNAME=	fly-1.6.5
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	${LOCALBASE}/bin/gif2png:../../graphics/gif2png
DEPENDS+=	gd>=1.8.1:../../graphics/gd

EVAL_PREFIX+=	XPMDIR=xpm
USE_X11=	yes						# (perhaps) -lXpm
CPPFLAGS+=	-I${XPMDIR}/include -I${XPMDIR}/include/X11	# Xpm.h
CPPFLAGS+=	-I${LOCALBASE}/include				# gd.h
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fly
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fly
	cd ${WRKSRC}/doc; ${LOCALBASE}/bin/gif2png *.gif
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png ${PREFIX}/share/doc/fly
	${RM} -f ${WRKSRC}/examples/*.orig
	cd ${WRKSRC}/examples; ${INSTALL_DATA} * ${PREFIX}/share/examples/fly

.include "../../mk/bsd.pkg.mk"
