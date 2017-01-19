# $NetBSD: Makefile,v 1.24 2017/01/19 18:52:22 agc Exp $
#

DISTNAME=	mpage-2.5.6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/
MASTER_SITES+=	http://www.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Print multiple pages per sheet of paper
HOMEPAGE=	http://www.mesa.nl/download.html
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_TARGET=	default
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	PAGESIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
