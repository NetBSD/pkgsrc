# $NetBSD: Makefile,v 1.60 2023/06/06 12:40:24 riastradh Exp $

DISTNAME=	bibtex2html-1.98
PKGREVISION=	19
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	hevea-[0-9]*:../../textproc/hevea
TOOL_DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
TOOL_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
TOOL_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	web2c-[0-9]*:../../print/web2c

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	aux2bib.1
SUBST_SED.paths=	-e 's,/usr/share,${PREFIX}/share,g'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

MAKE_ENV+=	ZLIB=-unsafe-string

.include "../../lang/ocaml/buildlink3.mk"

post-build:
	set -e; \
	cd ${WRKSRC} && ${MAKE} doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aux2bib ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bibtex2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bib2bib ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bib2bib.1
	${INSTALL_MAN} ${WRKSRC}/aux2bib.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/aux2bib.1
	${INSTALL_DATA} ${WRKSRC}/manual.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
