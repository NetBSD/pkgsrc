# $NetBSD: Makefile,v 1.1 2026/04/26 19:14:59 vins Exp $

DISTNAME=	${PKGNAME:S/-ns//}
PKGNAME=	docbook-xsl-ns-1.79.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=docbook/}
GITHUB_PROJECT=	xslt10-stylesheets
GITHUB_RELEASE=	release/${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docbook/xslt10-stylesheets/
COMMENT=	Docbook XSL modular stylesheet - Namespaced
LICENSE=	mit

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax perl

REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl-ns
XSLDIR=		${PREFIX}/share/xsl/docbook-ns
XML_CATALOGS=	${XSLDIR}/catalog.xml
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

NO_BUILD=	yes
AUTO_MKDIRS=	yes

CHECK_INTERPRETER_SKIP+=	share/xsl/docbook-ns/epub/bin/dbtoepub

post-extract:
	${RM} -f ${${FIND} ${WRKSRC} -type d:L:sh:=/.gitignore}
	chmod -R g-w ${WRKSRC}

do-install:
	cd ${WRKSRC}/template && ${PAX} -rw -pp -pm * ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION.xsl ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DESTDIR}${XSLDIR}/catalog.xml
	${RUN} for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/; \
	done
	${FIND} ${DESTDIR}${XSLDIR} -name '*.orig' -exec ${RM} {} \;

post-install:
	@${STEP_MSG} "Redirecting XML catalog entries to ${XSLDIR}"
	${RUN}${PERL5} -pi -e 's#rewritePrefix=\".*?\"#rewritePrefix="${XSLDIR}/"#g' \
		${DESTDIR}${XML_CATALOGS}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
