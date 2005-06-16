# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:51 jlam Exp $
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
INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${_DISTDIR}/uips.c ${WRKSRC}/
	${CP} ${_DISTDIR}/uips.txt ${WRKSRC}/
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uips ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uips
	${INSTALL_DATA} ${WRKSRC}/uips.txt ${PREFIX}/share/doc/uips

.include "../../mk/bsd.pkg.mk"
