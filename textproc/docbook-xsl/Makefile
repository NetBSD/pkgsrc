# $NetBSD: Makefile,v 1.45 2007/02/02 19:13:49 wiz Exp $
#

DISTNAME=	docbook-xsl-1.72.0
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

USE_TOOLS+=	perl:run
REPLACE_PERL+=	fo/pdf2index

EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS=	common extensions fo highlighting html htmlhelp images javahelp \
		lib manpages params profiling roundtrip slides website xhtml

XML_CATALOGS=	${XSLDIR}/catalog.xml

INSTALLATION_DIRS=	${EGDIR} ${XSLDIR}

do-install:
	cd ${WRKSRC}/template && ${PAX} -rw -pp -pm . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DESTDIR}${XSLDIR}/catalog.xml
	for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${DESTDIR}${XSLDIR}/; \
	done

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
