# $NetBSD: Makefile,v 1.16 2026/03/19 14:51:40 nia Exp $

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

FORCE_C_STD=	gnu89

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
