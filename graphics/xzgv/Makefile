# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 19:02:27 jtb Exp $

DISTNAME=	xzgv-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://xzgv.browser.org/

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
DEPENDS+=	glib-[0-9]*:../../devel/glib
DEPENDS+=	libungif-[0-9]*:../../graphics/libungif
DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg
DEPENDS+=	png-[0-9]*:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	imlib>=1.0:../../graphics/imlib

INFO_FILES=	xzgv
USE_X11BASE=	yes
USE_GMAKE=	yes

.if (${MACHINE_ARCH} == "i386")
MAKE_ENV+="CPPFLAGS=-DINTERP_MMX"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && makeinfo xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../mk/bsd.pkg.mk"

