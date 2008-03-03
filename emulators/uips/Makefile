# $NetBSD: Makefile,v 1.4 2008/03/03 19:21:38 jlam Exp $
#

DISTNAME=		uips
PKGNAME=		uips-1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.neillcorlett.com/uips/
DISTFILES=		uips.c uips.txt

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.neillcorlett.com/uips/
COMMENT=		IPS patcher with v2 support

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=		${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${_DISTDIR}/uips.c ${WRKSRC}/
	${CP} ${_DISTDIR}/uips.txt ${WRKSRC}/
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uips ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/uips
	${INSTALL_DATA} ${WRKSRC}/uips.txt ${DESTDIR}${PREFIX}/share/doc/uips

.include "../../mk/bsd.pkg.mk"
