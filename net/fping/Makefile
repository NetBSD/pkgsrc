# $NetBSD: Makefile,v 1.14 2014/05/09 15:28:53 sborrill Exp $

DISTNAME=	fping-3.10
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.org/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	YES

SPECIAL_PERMS+=		sbin/fping ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"
