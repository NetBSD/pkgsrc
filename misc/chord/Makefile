# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:10 jlam Exp $

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
