# $NetBSD: Makefile,v 1.6 2003/04/10 01:28:25 grant Exp $
#

DISTNAME=	website-2.3
PKGNAME=	docbook-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DocBook XML DTD for building websites

DEPENDS=	docbook-xsl>=1.58:../../textproc/docbook-xsl

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined
NO_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/docbook-website
DTDDIR=		${PREFIX}/share/xml/website
EGDIR=		${PREFIX}/share/examples/docbook-website

XML_CATALOGS=	${DTDDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rw ChangeLog README VERSION WhatsNew	\
		${DOCDIR}
	cd ${WRKSRC}/example && ${PAX} -rw . ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rw VERSION extensions xsl *.dtd *.mod	\
		${DTDDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
