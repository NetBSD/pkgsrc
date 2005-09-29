# $NetBSD: Makefile,v 1.30 2005/09/29 19:40:41 kristerw Exp $
#

DISTNAME=	docbook-xsl-1.69.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

DEPENDS=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_LANGUAGES=	# empty
NO_BUILD=	YES
NO_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/docbook-xsl
EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS=	common extensions fo html htmlhelp images javahelp \
		lib manpages params profiling xhtml

XML_CATALOGS=	${XSLDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/template && ${PAX} -rw -pp -pm . ${EGDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${XSLDIR}
	@for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${XSLDIR}/; \
	done
	${RM} ${XSLDIR}/common/pi.xsl.orig
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
