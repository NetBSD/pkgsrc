# $NetBSD: Makefile,v 1.8 2006/09/09 02:43:11 obache Exp $

DISTNAME=	procps-3.2.6
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/procps/watch/}
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}
MAKE_ENV+=	MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
