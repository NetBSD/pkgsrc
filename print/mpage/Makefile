# $NetBSD: Makefile,v 1.28 2021/03/14 08:40:46 wiz Exp $

DISTNAME=	mpage-2.5.7
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES+=	https://www.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa.nl/download.html
COMMENT=	Print multiple pages per sheet of paper
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_TARGET=		default
BUILD_DEFS+=		PAPERSIZE
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	PAGESIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
