# $NetBSD: Makefile,v 1.20 2004/04/26 10:34:09 recht Exp $
# FreeBSD Id: Makefile,v 1.17 1999/04/24 09:25:32 kuriyama Exp

DISTNAME=	db157
PKGNAME=	dsssl-docbook-modular-1.57
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/dsssl/
DISTFILES=	db157.zip db157d.zip

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://nwalsh.com/docbook/dsssl/
COMMENT=	DSSSL stylesheets for the DocBook DTD by Norman Walsh

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	docbook>=4.0:../../textproc/docbook

EXTRACT_CMD=	unzip ${DOWNLOADED_DISTFILE}
NO_MTREE=	yes

WRKSRC=		${WRKDIR}/docbook
USE_BUILDLINK3=	yes
INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

SGML_CATALOGS=	${INSTDIR}/catalog

do-build:
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
#	@${FIND} ${WRKDIR} -name '*~' -exec ${RM} {} \;
#	@${FIND} ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${CAT} ${FILESDIR}/install-note

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
