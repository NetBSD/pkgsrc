# $NetBSD: Makefile,v 1.8 2001/09/09 20:36:50 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1999/02/11 16:01:16 jfieber Exp
#

DISTNAME=	isoENTS
PKGNAME=	iso8879-1986
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.iso.ch/cate/d16387.html
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
WRKSRC=		${WRKDIR}

INSTDIR=	${PREFIX}/share/sgml/iso8879

pre-install:
	${MKDIR} ${INSTDIR}

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

.include "../../mk/bsd.pkg.mk"
