# $NetBSD: Makefile,v 1.6 2004/12/10 21:55:40 minskim Exp $

DISTNAME=	db2latex-xsl-0.8pre1
PKGNAME=	${DISTNAME:S/xsl-//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=db2latex/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://db2latex.sourceforge.net/
COMMENT=	Set of XSLT stylesheets converting DocBook to LaTeX2e

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGE=	# empty

DOCDIR=		${PREFIX}/share/doc/db2latex
XSLDIR=		${PREFIX}/share/xsl/db2latex

XML_ENTRIES=	system "http://db2latex.sourceforge.net/xsl/docbook.xsl" \
		${PREFIX}/share/xsl/db2latex/docbook.xsl

.include "../../textproc/xmlcatmgr/catalogs.mk"

post-extract:
	cd ${WRKSRC} && ${FIND} . -name "*\**" -exec ${RM} {} \;

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	cd ${WRKSRC}/doc && ${PAX} -rwpm . ${DOCDIR}
	cd ${WRKSRC} && ${PAX} -rwpm AUTHOR COPYING COPYRIGHT README \
		TODO VERSION ${DOCDIR}
	cd ${WRKSRC}/xsl && ${PAX} -rwpm . ${XSLDIR}

.include "../../mk/bsd.pkg.mk"
