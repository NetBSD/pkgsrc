# $NetBSD: Makefile,v 1.25 2005/02/18 16:17:43 wiz Exp $

DISTNAME=	docbook-dsssl-1.79
PKGNAME=	dsssl-docbook-modular-1.79
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-1.79${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DSSSL stylesheets for the DocBook DTD

DEPENDS+=	docbook>=4.0:../../textproc/docbook

NO_MTREE=	yes

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

SGML_CATALOGS=	${INSTDIR}/catalog

do-build:
	@${RM} -rf ${WRKSRC}/docsrc

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}

do-install:
	@${CP} -rp ${WRKSRC}/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
