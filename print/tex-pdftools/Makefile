# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 19:03:24 minskim Exp $

DISTNAME=	pdftools
PKGNAME=	tex-${DISTNAME}-0.82
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PDF-related utilities, including PostScript-to-PDF conversion
LICENSE=	public-domain

CONFLICTS=	texlive-pdftools<2011
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
DEPENDS+=	tex-oberdiek>=2011:../../print/tex-oberdiek
DEPENDS+=	tex-pst-pdf-[0-9]*:../../graphics/tex-pst-pdf
DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	xpdfopen-[0-9]*:../../print/xpdfopen

EVAL_PREFIX+=	EPSTOPDF_PREFIX=tex-epstopdf
USE_TOOLS+=	perl:run

REPLACE_PERL+=	bin/e2pall

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/e2pall
SUBST_SED.paths+=	-e 's,@EPSTOPDF@,${EPSTODPF_PREFIX}/bin/epstopdf,g'

INSTALLATION_DIRS+=	bin
TEX_TEXMF_DIRS=		# empty

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/tetex/e2pall.pl ${WRKSRC}/bin/e2pall

.include "../../mk/bsd.pkg.mk"
