# $NetBSD: Makefile,v 1.6 2006/05/15 16:01:03 tron Exp $

DISTNAME=	procps-3.2.6
PKGNAME=	${DISTNAME:S/procps/watch/}
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}
MAKE_ENV+=	MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
