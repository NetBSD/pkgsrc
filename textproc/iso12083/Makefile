# $NetBSD: Makefile,v 1.2 1999/03/14 16:17:42 rh Exp $
# FreeBSD Id: Makefile,v 1.2 1998/06/27 05:19:39 asami Exp
#

DISTNAME=	iso12083-1993
CATEGORIES=	textproc
MASTER_SITES=	ftp://info.ex.ac.uk/pub/SGML/ISO-12083/ \
		ftp://ftp.ifi.uio.no/pub/SGML/ISO12083/ \
		ftp://ftp.oit.unc.edu/pub/packages/SGML/oslo-mirror/ISO12083/
DISTFILES=	article.dtd book.dtd maths.dtd serial.dtd

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.oasis-open.org/cover/sgml-xml.html

DIST_SUBDIR=	iso12083

NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	# empty

INSTDIR=	${PREFIX}/share/sgml/iso12083

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@for i in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${INSTDIR}/$$i; \
	done
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog

.include "../../mk/bsd.pkg.mk"
