# $NetBSD: Makefile,v 1.21 2010/02/12 00:13:23 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	default
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	PAGESIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
