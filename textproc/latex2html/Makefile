# $NetBSD: Makefile,v 1.33 2009/02/25 17:18:08 minskim Exp $

DISTNAME=	latex2html-2002-2-1
PKGNAME=	latex2html-2002.2.1
PKGREVISION=	8
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2html/}

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.latex2html.org/
COMMENT=	LaTeX to HTML converter

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	netpbm>=10.29nb2:../../graphics/netpbm

TEX_ACCEPTED=		teTeX3
USE_DIRS+=		texmf-1.0
USE_TOOLS+=		gs:run perl:run
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-gif	# add support of GIF images
CONFIGURE_ARGS+=	--enable-png	# add support of PNG images
CONFIGURE_ARGS+=	--with-texpath=${PKG_LOCALTEXMFPREFIX}/tex/latex/html
CONFIGURE_ARGS+=	--shlibdir=${PREFIX}/share/latex2html
.if defined(LATEX2HTML_ICONPATH)
CONFIGURE_ARGS+=	--with-iconpath=${LATEX2HTML_ICONPATH:Q}
.endif
CONFIGURE_ARGS+=	--with-gs=${TOOLS_PATH.gs:Q}

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
