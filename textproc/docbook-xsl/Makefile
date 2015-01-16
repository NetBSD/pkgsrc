# $NetBSD: Makefile,v 1.60 2015/01/16 11:47:01 wiz Exp $

.include "Makefile.common"

COMMENT=	Docbook XSL modular stylesheet

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_TOOLS+=	perl:run

REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
# epub requires ruby, so we don't install the XSLMOD
XSLMODS=	common eclipse fo highlighting html \
		htmlhelp images javahelp lib manpages params \
		profiling roundtrip slides website xhtml xhtml-1_1

XML_CATALOGS=	${XSLDIR}/catalog.xml

INSTALLATION_DIRS=	${EGDIR} ${XSLDIR}

do-install:
	cd ${WRKSRC}/template && pax -rw -pp -pm . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION.xsl ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DESTDIR}${XSLDIR}/catalog.xml
	set -e; for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && pax -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/"; \
	    cd ${WRKSRC} && pax -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/; \
	done
	set -e; for f in `${FIND} ${DESTDIR}${XSLDIR} -name \\*.orig -print` ; do \
		${ECHO} "Remove .orig file $$f" ; \
		${RM} $$f ; \
	done

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
