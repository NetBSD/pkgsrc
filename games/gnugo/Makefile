# $NetBSD: Makefile,v 1.12 2003/08/04 07:51:23 wiz Exp $

DISTNAME=	gnugo-3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes

USE_NEW_TEXINFO=	YES
INFO_FILES=	gnugo.info

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
