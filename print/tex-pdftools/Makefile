# $NetBSD: Makefile,v 1.6 2013/12/12 04:44:17 minskim Exp $

DISTNAME=	pdftools
PKGNAME=	tex-${DISTNAME}-0.83
TEXLIVE_REV=	31660

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PDF-related utilities, including PostScript-to-PDF conversion
LICENSE=	public-domain

CONFLICTS=	texlive-pdftools<2011
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
DEPENDS+=	tex-oberdiek>=2011:../../print/tex-oberdiek
DEPENDS+=	tex-pst-pdf-[0-9]*:../../graphics/tex-pst-pdf
DEPENDS+=	web2c-[0-9]*:../../print/web2c

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
.include "options.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/e2pall.pl \
		${WRKSRC}/bin/e2pall

.include "../../mk/bsd.pkg.mk"
