# $NetBSD: Makefile,v 1.20 2008/10/04 14:51:16 reed Exp $
#

DISTNAME=	mpage-2.5.5
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/	\
		http://www.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Print multiple pages per sheet of paper
HOMEPAGE=	http://www.mesa.nl/download.html

BUILD_TARGET=	default
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	PAGESIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
