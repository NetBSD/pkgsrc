# $NetBSD: Makefile,v 1.52 2010/06/11 13:13:49 drochner Exp $
#

DISTNAME=	docbook-xsl-1.75.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
NO_BUILD=	YES

USE_TOOLS+=	pax perl:run
REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS=	common eclipse epub fo highlighting html \
		htmlhelp images javahelp lib manpages params \
		profiling roundtrip slides website xhtml xhtml-1_1

XML_CATALOGS=	${XSLDIR}/catalog.xml

INSTALLATION_DIRS=	${EGDIR} ${XSLDIR}

post-extract:
	${RUN} ${RM} -f ${${FIND} ${WRKSRC} -type d:L:sh:=/.gitignore}

do-install:
	cd ${WRKSRC}/template && pax -rw -pp -pm . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DESTDIR}${XSLDIR}/catalog.xml
	for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && pax -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/"; \
	    cd ${WRKSRC} && pax -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/; \
	done
	for f in `${FIND} ${DESTDIR}${XSLDIR} -name \\*.orig -print` ; do \
		${ECHO} "Remove .orig file $$f" ; \
		${RM} $$f ; \
	done

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
