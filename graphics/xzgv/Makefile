# $NetBSD: Makefile,v 1.6 2001/05/22 09:32:23 wiz Exp $

DISTNAME=	xzgv-0.7
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xzgv.browser.org/
COMMENT=	Image viewer

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
DEPENDS+=	glib-[0-9]*:../../devel/glib
DEPENDS+=	libungif-[0-9]*:../../graphics/libungif
DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	imlib>=1.0:../../graphics/imlib

INFO_FILES=	xzgv
USE_X11BASE=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && makeinfo xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../mk/bsd.pkg.mk"

