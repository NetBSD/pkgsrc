# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:57 wiz Exp $

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
