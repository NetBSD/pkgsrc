# $NetBSD: Makefile,v 1.13 2007/06/12 19:13:38 minskim Exp $

DISTNAME=	db2latex-xsl-0.8pre1
PKGNAME=	${DISTNAME:S/xsl-//}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=db2latex/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://db2latex.sourceforge.net/
COMMENT=	Set of XSLT stylesheets converting DocBook to LaTeX2e

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/db2latex
XSLDIR=		${PREFIX}/share/xsl/db2latex

XML_ENTRIES=	rewriteURI http://db2latex.sourceforge.net/xsl/ \
		${PREFIX}/share/xsl/db2latex/

.include "../../textproc/xmlcatmgr/catalogs.mk"

post-extract:
	cd ${WRKSRC} && ${FIND} . -name "*\\**" -exec ${RM} {} \;

pre-install:
	${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} \;

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	cd ${WRKSRC}/doc && ${PAX} -rwpm . ${DOCDIR}
	cd ${WRKSRC} && ${PAX} -rwpm AUTHOR COPYING COPYRIGHT README \
		TODO VERSION ${DOCDIR}
	cd ${WRKSRC}/xsl && ${PAX} -rwpm . ${XSLDIR}

.include "../../mk/bsd.pkg.mk"
