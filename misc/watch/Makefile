# $NetBSD: Makefile,v 1.10 2008/02/22 02:14:53 tnn Exp $

DISTNAME=	procps-3.2.6
PKGNAME=	watch-3.2.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	${BSD_MAKE_ENV}
MAKE_ENV+=	LIBS=${LIBS:Q}

LIBS.SunOS+=	-lrt
USE_FEATURES+=	asprintf getopt_long

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
