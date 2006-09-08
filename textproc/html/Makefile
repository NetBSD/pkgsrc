# $NetBSD: Makefile,v 1.20 2006/09/08 07:41:46 rillig Exp $
#

DISTNAME=	html-4.01
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w3.org/TR/REC-html40/
COMMENT=	SGML DTDs for the Hypertext Markup Language

DEPENDS+=	iso8879>=1986:../../textproc/iso8879

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
USE_TOOLS+=	tar

INSTDIR=        ${PREFIX}/share/sgml/html
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SGML_CATALOGS=	${INSTDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${INSTDIR}
	cd ${INSTDIR} && \
		${TAR} -zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
