# $NetBSD: Makefile,v 1.24 2004/09/24 13:09:11 wiz Exp $
# FreeBSD Id: Makefile,v 1.17 1999/04/24 09:25:32 kuriyama Exp

DISTNAME=	docbook-dsssl-1.78
PKGNAME=	dsssl-docbook-modular-1.78
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
DISTFILES=	${DISTNAME}.tar.gz  docbook-dsssl-doc-1.78.tar.gz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://nwalsh.com/docbook/dsssl/
COMMENT=	DSSSL stylesheets for the DocBook DTD by Norman Walsh

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
