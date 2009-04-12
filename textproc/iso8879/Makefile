# $NetBSD: Makefile,v 1.30 2009/04/12 07:00:29 minskim Exp $

DISTNAME=	ISOEnts
PKGNAME=	iso8879-1986
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/cover/
EXTRACT_SUFX=	.zip

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.iso.org/cate/d16387.html
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_TOOLS+=	unzip
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

INSTALLATION_DIRS=	share/sgml/iso8879

INSTDIR=	${DESTDIR}${PREFIX}/share/sgml/iso8879

SGML_CATALOGS=	${PREFIX}/share/sgml/iso8879

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
