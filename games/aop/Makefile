# $NetBSD: Makefile,v 1.8 2020/04/26 13:54:59 rillig Exp $

DISTNAME=	aop-0.6
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://raffi.at/code/aop/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://raffi.at/view/code/aop/
COMMENT=	Aop is a curses based arcade game with only 64 lines of sourcecode

SUBST_CLASSES+=			destination
SUBST_FILES.destination=	aop.c
SUBST_STAGE.destination=	pre-configure
SUBST_SED.destination=		-e 's:/usr/local:${PREFIX}:g'

BUILD_TARGET=	aop

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
