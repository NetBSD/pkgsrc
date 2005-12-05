# $NetBSD: Makefile,v 1.22 2005/12/05 20:51:03 rillig Exp $

DISTNAME=	ISOEnts
PKGNAME=	iso8879-1986
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/cover/
EXTRACT_SUFX=	.zip

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.iso.ch/cate/d16387.html
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

PKG_INSTALLATION_TYPES= overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_MTREE=       yes
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
