# $NetBSD: Makefile,v 1.17 2005/03/20 13:06:59 schwarz Exp $

DISTNAME=	gnugo-3.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

INFO_FILES=	gnugo.info

TEST_TARGET=	check

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
