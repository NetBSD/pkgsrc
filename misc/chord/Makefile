# $NetBSD: Makefile,v 1.15 2012/10/08 09:57:17 asau Exp $

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
