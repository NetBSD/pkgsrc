# $NetBSD: Makefile,v 1.17 2002/03/14 23:30:00 tron Exp $

DISTNAME=	fly-1.6.5
PKGREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	gif2png>=2.4.2:../../graphics/gif2png
DEPENDS+=	gd>=1.8.4nb1:../../graphics/gd

EVAL_PREFIX+=	XPMDIR=xpm
USE_X11=	yes						# (perhaps) -lXpm
CPPFLAGS+=	-I${XPMDIR}/include -I${XPMDIR}/include/X11	# Xpm.h
CPPFLAGS+=	-I${LOCALBASE}/include				# gd.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fly
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fly
	cd ${WRKSRC}/doc; ${LOCALBASE}/bin/gif2png *.gif
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png ${PREFIX}/share/doc/fly
	${RM} -f ${WRKSRC}/examples/*.orig
	cd ${WRKSRC}/examples; ${INSTALL_DATA} * ${PREFIX}/share/examples/fly

.include "../../mk/bsd.pkg.mk"
