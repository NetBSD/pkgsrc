# $NetBSD: Makefile,v 1.34 2009/05/21 16:15:44 sno Exp $

DISTNAME=	latex2html-2008
#PKGNAME=	latex2html-2008
CATEGORIES=	textproc converters
#MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2html/}
MASTER_SITES=	http://saftsack.fs.uni-bayreuth.de/~latex2ht/current/

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

REPLACE_PERL+=		l2hconf.pin cweb2html/cweb2html cweb2html/makemake.pl
REPLACE_PERL+=		makemap makeseg/makeseg

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
