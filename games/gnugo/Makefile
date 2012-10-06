# $NetBSD: Makefile,v 1.26 2012/10/06 11:54:41 asau Exp $

DISTNAME=	gnugo-3.8
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnugo/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnugo/
COMMENT=	Go playing program
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
