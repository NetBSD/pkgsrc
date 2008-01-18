# $NetBSD: Makefile,v 1.7 2008/01/18 21:30:04 rillig Exp $
#

DISTNAME=		asciidoc-8.2.5
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${HOMEPAGE}	\
			${MASTER_SITE_SOURCEFORGE:=asciidoc/}

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.methods.co.nz/asciidoc/
COMMENT=		ASCII to formatted document converter

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=		getopt-[0-9]*:../../misc/getopt

REPLACE_BASH+=		a2x
USE_TOOLS+=		bash:run
PYTHON_VERSIONS_INCOMPATIBLE=	15 20 21 22
PYTHON_PATCH_SCRIPTS=	asciidoc.py
NO_BUILD=		yes

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		a2x asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1 = "${PREFIX}/share/asciidoc",'

INSTALLATION_DIRS=	bin share/asciidoc share/asciidoc/filters \
			share/asciidoc/docbook-xsl share/asciidoc/stylesheets \
			share/asciidoc/javascripts \
			share/asciidoc/images/icons/callouts \
			${PKGMANDIR}/man1

DOCDIR=		${PREFIX}/share/doc/asciidoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${PREFIX}/bin/asciidoc
	${INSTALL_SCRIPT} ${WRKSRC}/a2x ${PREFIX}/bin/a2x
	${INSTALL_MAN} ${WRKSRC}/doc/asciidoc.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/asciidoc.html ${DOCDIR}

	cd ${WRKSRC} && ${PAX} -wr -pma *.conf filters/*.py \
		filters/*.conf docbook-xsl/*.xsl stylesheets/*.css	\
		javascripts/*.js images/icons/callouts/* images/icons/*.png \
		images/icons/README \
		${PREFIX}/share/asciidoc/.

do-test:
	cd ${WRKSRC} && ./asciidoc.py -v doc/asciidoc.txt

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
