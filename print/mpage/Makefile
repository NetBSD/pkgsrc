# $NetBSD: Makefile,v 1.27 2020/03/24 18:12:08 nia Exp $

DISTNAME=	mpage-2.5.7
CATEGORIES=	print
MASTER_SITES+=	https://www.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Print multiple pages per sheet of paper
HOMEPAGE=	https://www.mesa.nl/download.html
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_TARGET=		default
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	PAGESIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
