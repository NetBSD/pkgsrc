# $NetBSD: Makefile,v 1.23 2008/06/20 01:09:20 joerg Exp $

DISTNAME=	gnugo-3.6
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
INFO_FILES=	# PLIST

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
