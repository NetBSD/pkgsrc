# $NetBSD: Makefile,v 1.25 2008/05/26 02:13:24 joerg Exp $
#

DISTNAME=	docbook-website-2.6.0
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DocBook XML DTD for building websites

DEPENDS+=	docbook-simple-[0-9]*:../../textproc/docbook-simple
DEPENDS+=	docbook-xsl>=1.58:../../textproc/docbook-xsl

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax
NO_BUILD=	YES
NO_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/docbook-website
DTDDIR=		${PREFIX}/share/xml/website
EGDIR=		${PREFIX}/share/examples/docbook-website

XML_CATALOGS=	${DTDDIR}/catalog.xml
SGML_CATALOGS=	${DTDDIR}/catalog

do-install:
	cd ${WRKSRC} && ${FIND} . -name "*.orig" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && pax -rwpm ChangeLog README VERSION \
		RELEASE-NOTES.html RELEASE-NOTES.txt RELEASE-NOTES.xml \
		TODO ${DOCDIR}
	cd ${WRKSRC}/example && pax -rwpm . ${EGDIR}
	cd ${WRKSRC} && pax -rwpm VERSION extensions schema xsl \
		${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${WRKSRC}/catalog ${DTDDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
