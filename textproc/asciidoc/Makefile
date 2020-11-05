# $NetBSD: Makefile,v 1.54 2020/11/05 09:09:12 ryoon Exp $

DISTNAME=	asciidoc-py3-9.0.3
PKGNAME=	${DISTNAME:S/-py3//}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=asciidoc/}
GITHUB_PROJECT=	asciidoc-py3

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://www.asciidoc.org/
COMMENT=	ASCII to formatted document converter
LICENSE=	gnu-gpl-v2

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	getopt-[0-9]*:../../misc/getopt

USE_TOOLS+=		pax

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		a2x.py asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1="${PREFIX}/share/asciidoc",'

REPLACE_PYTHON+=	a2x.py
REPLACE_PYTHON+=	asciidoc.py
REPLACE_PYTHON+=	asciidocapi.py
REPLACE_PYTHON+=	filters/code/code-filter.py
REPLACE_PYTHON+=	filters/latex/latex2img.py
REPLACE_PYTHON+=	filters/music/music2png.py
REPLACE_PYTHON+=	filters/graphviz/graphviz2png.py
REPLACE_PYTHON+=	filters/unwraplatex.py
REPLACE_PYTHON+=	tests/testasciidoc.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS=	bin share/asciidoc share/asciidoc/filters \
			share/asciidoc/docbook-xsl share/asciidoc/stylesheets \
			share/asciidoc/javascripts \
			share/asciidoc/images/icons/callouts \
			${PKGMANDIR}/man1 ${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/asciidoc

.include "options.mk"

do-build:
	cd ${WRKSRC} && \
		${PYTHONBIN} a2x.py -f manpage doc/a2x.1.txt && \
		${PYTHONBIN} a2x.py -f manpage doc/asciidoc.1.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${DESTDIR}${PREFIX}/bin/asciidoc
	${INSTALL_SCRIPT} ${WRKSRC}/a2x.py ${DESTDIR}${PREFIX}/bin/a2x
	${INSTALL_MAN} ${WRKSRC}/doc/asciidoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.txt ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && pax -wr -pma *.conf filters docbook-xsl/*.xsl \
		stylesheets/*.css javascripts/*.js images/* dblatex/* \
		${DESTDIR}${PREFIX}/share/asciidoc/.

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} asciidoc.py -v doc/asciidoc.txt

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
