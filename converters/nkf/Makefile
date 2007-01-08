# $NetBSD: Makefile,v 1.10 2007/01/08 13:34:12 obache Exp $

DISTNAME=	nkf205
PKGNAME=	nkf-2.05
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=nkf/15302/} \
		http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nkf/
COMMENT=	Convert between various Japanese character encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
