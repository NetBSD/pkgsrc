# $NetBSD: Makefile,v 1.14 2010/02/11 19:02:01 joerg Exp $

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
