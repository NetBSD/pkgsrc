# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:24 wiz Exp $
#

DISTNAME=	html-4.0b
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.w3.org/TR/REC-html40/
COMMENT=	SGML DTDs for the Hypertext Markup Language

DEPENDS+=	iso8879-1986:../../textproc/iso8879

NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

INSTDIR=        ${PREFIX}/share/sgml/html
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	${GTAR} -plzx -C ${INSTDIR} -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/catalog

.include "../../mk/bsd.pkg.mk"
