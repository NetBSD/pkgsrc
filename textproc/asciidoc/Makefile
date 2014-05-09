# $NetBSD: Makefile,v 1.41 2014/05/09 07:37:20 wiz Exp $

DISTNAME=		asciidoc-8.6.9
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asciidoc/}

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://www.asciidoc.org/
COMMENT=		ASCII to formatted document converter
LICENSE=		gnu-gpl-v2

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=		getopt-[0-9]*:../../misc/getopt

USE_TOOLS+=		pax
REPLACE_PYTHON=	a2x.py asciidoc.py asciidocapi.py
REPLACE_PYTHON+=	filters/code/code-filter.py
REPLACE_PYTHON+=	filters/latex/latex2png.py
REPLACE_PYTHON+=	filters/music/music2png.py
REPLACE_PYTHON+=	filters/graphviz/graphviz2png.py
REPLACE_PYTHON+=	tests/testasciidoc.py tests/asciidocapi.py

NO_BUILD=		yes

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		a2x.py asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1="${PREFIX}/share/asciidoc",'

REPLACE_PYTHON+=	a2x.py
REPLACE_PYTHON+=	asciidoc.py
REPLACE_PYTHON+=	asciidocapi.py
REPLACE_PYTHON+=	filters/code/code-filter.py
REPLACE_PYTHON+=	filters/latex/latex2png.py
REPLACE_PYTHON+=	filters/music/music2png.py
REPLACE_PYTHON+=	filters/graphviz/graphviz2png.py
REPLACE_PYTHON+=	tests/testasciidoc.py
REPLACE_PYTHON+=	tests/asciidocapi.py
REPLACE_PYTHON+=	html5.conf xhtml11.conf xhtml11-quirks.conf

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 8.6.9 (as seen e.g. in git-docs)

INSTALLATION_DIRS=	bin share/asciidoc share/asciidoc/filters \
			share/asciidoc/docbook-xsl share/asciidoc/stylesheets \
			share/asciidoc/javascripts \
			share/asciidoc/images/icons/callouts \
			${PKGMANDIR}/man1 ${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/asciidoc

.include "options.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${DESTDIR}${PREFIX}/bin/asciidoc
	${INSTALL_SCRIPT} ${WRKSRC}/a2x.py ${DESTDIR}${PREFIX}/bin/a2x
	${INSTALL_MAN} ${WRKSRC}/doc/asciidoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.txt ${DESTDIR}${DOCDIR}

	cd ${WRKSRC} && pax -wr -pma *.conf filters \
		docbook-xsl/*.xsl stylesheets/*.css	\
		javascripts/*.js images/* dblatex/* \
		${DESTDIR}${PREFIX}/share/asciidoc/.

	cd ${WRKSRC}/doc && pax -wr -pma *.csv *.txt *.pdf *.epub \
		${DESTDIR}${DOCDIR}

do-test:
	cd ${WRKSRC} && ./asciidoc.py -v doc/asciidoc.txt

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
