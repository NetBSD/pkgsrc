# $NetBSD: Makefile,v 1.49 2018/08/22 09:46:46 wiz Exp $

DISTNAME=	latex2html-2016
PKGREVISION=	2
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2html/}

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.latex2html.org/
COMMENT=	LaTeX to HTML converter
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	tex-url>=1.4:../../print/tex-url
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	netpbm>=10.29nb2:../../graphics/netpbm

USE_TOOLS+=		gs:run perl:run
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-gif	# add support of GIF images
CONFIGURE_ARGS+=	--enable-png	# add support of PNG images
CONFIGURE_ARGS+=	--with-texpath=${PREFIX}/share/texmf-dist/tex/latex/html
CONFIGURE_ARGS+=	--shlibdir=${PREFIX}/share/latex2html
.if defined(LATEX2HTML_ICONPATH)
CONFIGURE_ARGS+=	--with-iconpath=${LATEX2HTML_ICONPATH:Q}
.endif
CONFIGURE_ARGS+=	--with-gs=${TOOLS_PATH.gs:Q}

MAKE_ENV+=		DESTDIR=${DESTDIR}

REPLACE_PERL+=		l2hconf.pin cweb2html/cweb2html cweb2html/makemake.pl
REPLACE_PERL+=		makemap makeseg/makeseg

post-extract:	; ${RM} ${WRKSRC}/texinputs/url.sty ${WRKSRC}/docs/url.sty

.include "../../print/kpathsea/texmf.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
