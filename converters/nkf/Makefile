# $NetBSD: Makefile,v 1.11 2008/01/13 13:13:42 obache Exp $

DISTNAME=	nkf-2.0.8b
PKGNAME=	nkf-2.08b
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=nkf/26243/}

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nkf/
COMMENT=	Convert between various Japanese character encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nkf-2.0.8

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
