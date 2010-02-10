# $NetBSD: Makefile,v 1.19 2010/02/10 19:17:46 joerg Exp $
#

DISTNAME=		asciidoc-8.3.3
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${HOMEPAGE}	\
			${MASTER_SITE_SOURCEFORGE:=asciidoc/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.methods.co.nz/asciidoc/
COMMENT=		ASCII to formatted document converter

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=		getopt-[0-9]*:../../misc/getopt

REPLACE_BASH+=		a2x
USE_TOOLS+=		bash:run pax
PYTHON_PATCH_SCRIPTS=	asciidoc.py
PYTHON_PATCH_SCRIPTS+=	filters/code/code-filter.py
PYTHON_PATCH_SCRIPTS+=	filters/music/music2png.py
PYTHON_PATCH_SCRIPTS+=	filters/graphviz/graphviz2png.py

NO_BUILD=		yes

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		a2x asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1="${PREFIX}/share/asciidoc",'

INSTALLATION_DIRS=	bin share/asciidoc share/asciidoc/filters \
			share/asciidoc/docbook-xsl share/asciidoc/stylesheets \
			share/asciidoc/javascripts \
			share/asciidoc/images/icons/callouts \
			${PKGMANDIR}/man1 ${DOCDIR}

DOCDIR=		${PREFIX}/share/doc/asciidoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${DESTDIR}${PREFIX}/bin/asciidoc
	${INSTALL_SCRIPT} ${WRKSRC}/a2x ${DESTDIR}${PREFIX}/bin/a2x
	${INSTALL_MAN} ${WRKSRC}/doc/asciidoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.html ${DESTDIR}${DOCDIR}

	cd ${WRKSRC} && pax -wr -pma *.conf filters \
		filters docbook-xsl/*.xsl stylesheets/*.css	\
		javascripts/*.js images/icons/callouts/* images/icons/*.png \
		images/icons/README \
		${DESTDIR}${PREFIX}/share/asciidoc/.

do-test:
	cd ${WRKSRC} && ./asciidoc.py -v doc/asciidoc.txt

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
