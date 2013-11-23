# $NetBSD: Makefile,v 1.36 2013/11/23 18:37:40 gls Exp $
#

DISTNAME=		asciidoc-8.6.9
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asciidoc/}

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://www.asciidoc.org/
COMMENT=		ASCII to formatted document converter
LICENSE=		gnu-gpl-v2

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=		getopt-[0-9]*:../../misc/getopt

USE_TOOLS+=		pax
PYTHON_PATCH_SCRIPTS=	a2x.py asciidoc.py asciidocapi.py
PYTHON_PATCH_SCRIPTS+=	filters/code/code-filter.py
PYTHON_PATCH_SCRIPTS+=	filters/latex/latex2png.py
PYTHON_PATCH_SCRIPTS+=	filters/music/music2png.py
PYTHON_PATCH_SCRIPTS+=	filters/graphviz/graphviz2png.py
PYTHON_PATCH_SCRIPTS+=	tests/testasciidoc.py tests/asciidocapi.py

NO_BUILD=		yes

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		a2x.py asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1="${PREFIX}/share/asciidoc",'

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	a2x.py asciidoc.conf html5.conf xhtml11.conf xhtml11-quirks.conf

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
