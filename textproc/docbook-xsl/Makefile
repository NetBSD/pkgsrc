# $NetBSD: Makefile,v 1.68 2020/01/05 18:54:40 adam Exp $

DISTNAME=	docbook-xsl-1.79.1
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax perl:run
NO_BUILD=	yes

REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
# epub requires ruby, so we don't install the XSLMOD
XSLMODS=	common eclipse epub epub3 fo highlighting html \
		htmlhelp images javahelp lib manpages params \
		profiling roundtrip slides website xhtml xhtml-1_1 \
		xhtml5

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
	${FIND} ${DESTDIR}${XSLDIR} -name '*.orig' -exec ${RM} {} +

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
