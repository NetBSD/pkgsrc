# $NetBSD: Makefile,v 1.10 2004/04/26 10:34:09 recht Exp $
#

DISTNAME=	html-4.0b
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.w3.org/TR/REC-html40/
COMMENT=	SGML DTDs for the Hypertext Markup Language

DEPENDS+=	iso8879>=1986:../../textproc/iso8879

WRKSRC=		${WRKDIR}
NO_MTREE=	yes
USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

INSTDIR=        ${PREFIX}/share/sgml/html
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SGML_CATALOGS=	${INSTDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	${GTAR} -plzx -C ${INSTDIR} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
