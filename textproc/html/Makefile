# $NetBSD: Makefile,v 1.4 2003/01/11 22:10:58 jmmv Exp $
#

DISTNAME=	html-4.0b
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.w3.org/TR/REC-html40/
COMMENT=	SGML DTDs for the Hypertext Markup Language

DEPENDS+=	iso8879>=1986:../../textproc/iso8879

NO_MTREE=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTDIR=        ${PREFIX}/share/sgml/html
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	${GTAR} -plzx -C ${INSTDIR} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/catalog
	${PREFIX}/bin/xmlcatmgr -c ${PREFIX}/share/sgml/catalog add \
		CATALOG ${INSTDIR}/catalog

.include "../../textproc/xmlcatmgr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
