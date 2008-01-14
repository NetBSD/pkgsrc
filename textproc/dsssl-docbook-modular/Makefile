# $NetBSD: Makefile,v 1.31 2008/01/14 23:18:12 heinz Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	docbook>=4.0:../../textproc/docbook

NO_MTREE=	yes

USE_LANGUAGES=	# empty
INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

SGML_CATALOGS=	${INSTDIR}/catalog

do-build:
	@${RM} -rf ${WRKSRC}/docsrc

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${INSTDIR}

do-install:
	@${CP} -rp ${WRKSRC}/* ${DESTDIR}${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
