# $NetBSD: Makefile,v 1.3 2003/01/28 10:43:43 grant Exp $
#

DISTNAME=	website-2.3
PKGNAME=	docbook-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DocBook XML DTD for building websites

DEPENDS=	docbook-xsl>=1.58:../../textproc/docbook-xsl

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined
NO_CONFIGURE=	# defined
NO_PATCH=	# defined

DOCDIR=		${PREFIX}/share/doc/docbook-website
DTDDIR=		${PREFIX}/share/xml/website
EGDIR=		${PREFIX}/share/examples/docbook-website

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	@cd ${WRKSRC}; ${PAX} -rw ChangeLog README VERSION WhatsNew	\
		${DOCDIR}
	@cd ${WRKSRC}/example; ${PAX} -rw . ${EGDIR}
	@cd ${WRKSRC}; ${PAX} -rw VERSION extensions xsl *.dtd *.mod	\
		${DTDDIR}
	${PREFIX}/bin/xmlcatmgr -c ${PREFIX}/share/xml/catalog \
		add "CATALOG" "${PREFIX}/share/xml/website/catalog"
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
