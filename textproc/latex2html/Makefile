# $NetBSD: Makefile,v 1.18 2005/09/28 20:52:27 rillig Exp $

DISTNAME=	latex2html-2002-2-1
PKGNAME=	latex2html-2002.2.1
PKGREVISION=	3
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2html/}

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.latex2html.org/
COMMENT=	LaTeX to HTML converter

DEPENDS+=       teTeX-bin>=1.0.6:../../print/teTeX-bin
DEPENDS+=	netpbm>=10.29nb2:../../graphics/netpbm

USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-gif	# add support of GIF images
CONFIGURE_ARGS+=	--enable-png	# add support of PNG images
CONFIGURE_ARGS+=	--with-texpath=${PREFIX}/share/texmf/tex/latex/html
CONFIGURE_ARGS+=	--shlibdir=${PREFIX}/share/latex2html
.if defined(LATEX2HTML_ICONPATH)
CONFIGURE_ARGS+=	--with-iconpath=${LATEX2HTML_ICONPATH}
.endif

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
