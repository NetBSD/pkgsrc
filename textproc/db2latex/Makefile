# $NetBSD: Makefile,v 1.14 2008/05/26 02:13:24 joerg Exp $

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
USE_TOOLS+=	pax

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
	cd ${WRKSRC}/doc && pax -rwpm . ${DOCDIR}
	cd ${WRKSRC} && pax -rwpm AUTHOR COPYING COPYRIGHT README \
		TODO VERSION ${DOCDIR}
	cd ${WRKSRC}/xsl && pax -rwpm . ${XSLDIR}

.include "../../mk/bsd.pkg.mk"
