# $NetBSD: Makefile,v 1.30 2006/03/21 06:00:49 jlam Exp $

DISTNAME=	docbook-dsssl-1.79
PKGNAME=	dsssl-docbook-modular-1.79
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-1.79${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DSSSL stylesheets for the DocBook DTD

DEPENDS+=	docbook>=4.0:../../textproc/docbook

NO_MTREE=	yes

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
