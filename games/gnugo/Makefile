# $NetBSD: Makefile,v 1.25 2011/12/17 10:15:32 sbd Exp $

DISTNAME=	gnugo-3.8
PKGREVISION=	1
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

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
