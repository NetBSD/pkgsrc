# $NetBSD: Makefile,v 1.16 2005/02/19 00:44:52 wiz Exp $
#

DISTNAME=	website-2.3
PKGNAME=	docbook-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DocBook XML DTD for building websites

DEPENDS=	docbook-xsl>=1.58:../../textproc/docbook-xsl

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
NO_BUILD=	# defined
NO_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/docbook-website
DTDDIR=		${PREFIX}/share/xml/website
EGDIR=		${PREFIX}/share/examples/docbook-website

XML_CATALOGS=	${DTDDIR}/catalog

do-install:
	cd ${WRKSRC} && ${FIND} . -name "*.orig" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rwpm ChangeLog README VERSION WhatsNew	\
		${DOCDIR}
	cd ${WRKSRC}/example && ${PAX} -rwpm . ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rwpm VERSION extensions xsl *.dtd *.mod	\
		${DTDDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
