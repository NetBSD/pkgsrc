# $NetBSD: Makefile,v 1.1.1.1 2004/02/27 15:35:57 wiz Exp $
#

DISTNAME=		uips
PKGNAME=		uips-1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.neillcorlett.com/uips/
DISTFILES=		uips.c uips.txt

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.neillcorlett.com/uips/
COMMENT=		IPS patcher with v2 support

DIST_SUBDIR=		${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes

do-extract:
	${CP} ${_DISTDIR}/uips.c ${WRKSRC}/
	${CP} ${_DISTDIR}/uips.txt ${WRKSRC}/
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uips ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uips
	${INSTALL_DATA} ${WRKSRC}/uips.txt ${PREFIX}/share/doc/uips

.include "../../mk/bsd.pkg.mk"
