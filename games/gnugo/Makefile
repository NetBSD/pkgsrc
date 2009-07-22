# $NetBSD: Makefile,v 1.24 2009/07/22 13:30:59 wiz Exp $

DISTNAME=	gnugo-3.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
