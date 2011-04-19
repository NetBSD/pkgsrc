# $NetBSD: Makefile,v 1.54 2011/04/19 06:32:47 roy Exp $

DISTNAME=	docbook-xsl-1.76.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax perl:run
NO_BUILD=	yes

REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
# epub requires ruby, so we don't install the XSLMOD
XSLMODS=	common eclipse fo highlighting html \
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
