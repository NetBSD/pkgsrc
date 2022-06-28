# $NetBSD: Makefile,v 1.78 2022/06/28 11:36:09 wiz Exp $

DISTNAME=	docbook-xsl-nons-1.79.2
PKGNAME=	${DISTNAME:S/-nons//}
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=docbook/}
GITHUB_PROJECT=	xslt10-stylesheets
GITHUB_RELEASE=	release/${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docbook/xslt10-stylesheets/
COMMENT=	Docbook XSL modular stylesheet

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax perl:run
NO_BUILD=	yes

REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS+=	assembly
XSLMODS+=	common
#XSLMODS+=	doc # empty
#XSLMODS+=	docsrc # source f
XSLMODS+=	eclipse
XSLMODS+=	epub
XSLMODS+=	epub3
#XSLMODS+=	extensions # java tools
XSLMODS+=	fo
XSLMODS+=	highlighting
XSLMODS+=	html
XSLMODS+=	htmlhelp
XSLMODS+=	images
XSLMODS+=	javahelp
XSLMODS+=	lib
XSLMODS+=	manpages
XSLMODS+=	params
XSLMODS+=	profiling
XSLMODS+=	roundtrip
XSLMODS+=	slides
#XSLMODS+=	template # documentation
#XSLMODS+=	tests # test data
#XSLMODS+=	tools # java tools
#XSLMODS+=	webhelp # HTML help
XSLMODS+=	website
XSLMODS+=	xhtml-1_1
XSLMODS+=	xhtml
XSLMODS+=	xhtml5

XML_CATALOGS=	${XSLDIR}/catalog.xml

INSTALLATION_DIRS=	${EGDIR} ${XSLDIR}

CHECK_INTERPRETER_SKIP+=	share/xsl/docbook/epub/bin/dbtoepub

post-extract:
	${RM} -f ${${FIND} ${WRKSRC} -type d:L:sh:=/.gitignore}

do-install:
	cd ${WRKSRC}/template && ${PAX} -rw -pp -pm . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION.xsl ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DESTDIR}${XSLDIR}/catalog.xml
	${RUN} for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/; \
	done
	${FIND} ${DESTDIR}${XSLDIR} -name '*.orig' -exec ${RM} {} \;

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
