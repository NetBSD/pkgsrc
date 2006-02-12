# $NetBSD: Makefile,v 1.5 2006/02/12 18:57:21 rillig Exp $
#

DISTNAME=	procps-2.0.2
PKGNAME=	watch-2.0.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.slackware.org/pub/linux/slackware/source/a/procps/ \
		${MASTER_SITE_SUNSITE:=slackware/source/a/procps/}

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}
MAKE_ENV+=	MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

.include "../../mk/bsd.pkg.mk"
