# $NetBSD: Makefile,v 1.9 2006/10/25 21:37:51 rillig Exp $

DISTNAME=	procps-3.2.6
PKGNAME=	watch-3.2.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	${BSD_MAKE_ENV}
MAKE_ENV+=	LIBS=${LIBS}

LIBS.SunOS+=	-lrt

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
