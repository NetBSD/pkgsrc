# $NetBSD: Makefile,v 1.14 2004/01/24 13:30:56 grant Exp $

DISTNAME=	gnugo-3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes

INFO_FILES=	gnugo.info

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
