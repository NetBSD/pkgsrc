# $NetBSD: Makefile,v 1.11 2003/09/22 12:29:19 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/04/30 03:18:06 asami Exp
#

DISTNAME=	chord
PKGNAME=	chord-3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Produce PS sheet-music from text input

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

CFLAGS+=	-DPAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
