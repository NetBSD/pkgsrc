# $NetBSD: Makefile,v 1.2 2004/01/05 06:20:29 kristerw Exp $

DISTNAME=	db2latex-0.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=db2latex/}

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://db2latex.sourceforge.net/
COMMENT=	Set of XSLT stylesheets converting DocBook to LaTeX2e

USE_BUILDLINK2=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/db2latex
XSLDIR=		${PREFIX}/share/xsl/db2latex
EGDIR=		${PREFIX}/share/examples/db2latex

XML_CATALOGS=	${XSLDIR}/catalog

do-install:
	cd ${WRKSRC} && ${FIND} . -name "*.orig" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc && ${PAX} -rwpm . ${DOCDIR}
	cd ${WRKSRC} && ${PAX} -rwpm AUTHOR COPYING COPYRIGHT README \
		TODO VERSION ${DOCDIR}
	cd ${WRKSRC}/xsl && ${PAX} -rwpm slides ${DOCDIR}
	cd ${WRKSRC}/xsl && ${PAX} -rwpm *.xsl *.dtd *.xml common ${XSLDIR}
	cd ${WRKSRC}/xsl/sample && ${PAX} -rwpm . ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
