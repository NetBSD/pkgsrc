# $NetBSD: Makefile,v 1.15 2004/04/26 10:34:09 recht Exp $
# FreeBSD Id: Makefile,v 1.9 1999/02/11 16:01:16 jfieber Exp
#

DISTNAME=	isoENTS
PKGNAME=	iso8879-1986
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.iso.ch/cate/d16387.html
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

WRKSRC=		${WRKDIR}
NO_MTREE=       yes
USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes

INSTDIR=	${PREFIX}/share/sgml/iso8879

SGML_CATALOGS=	${INSTDIR}/catalog

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
