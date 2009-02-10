# $NetBSD: Makefile,v 1.12 2009/02/10 17:26:05 joerg Exp $

DISTNAME=	fping-2.4b2_to
PKGNAME=	fping-2.4b2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

SPECIAL_PERMS+=		sbin/fping ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"
