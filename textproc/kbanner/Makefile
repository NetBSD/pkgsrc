# $NetBSD: Makefile,v 1.9 2022/08/19 02:34:51 tnn Exp $

DISTNAME=	kbanner2
PKGNAME=	kbanner-2.1
CATEGORIES=	textproc japanese
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/program/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/program.html
COMMENT=	Display kanji files in large letters

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_TARGET=	kbanner

DIST_SUBDIR=	${DISTNAME}-20040713

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kbanner ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kbanner.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
