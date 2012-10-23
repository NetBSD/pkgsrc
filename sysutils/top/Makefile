# $NetBSD: Makefile,v 1.38 2012/10/23 19:51:27 asau Exp $

DISTNAME=	top-3.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		SET_OWNER=${BINOWN}
CONFIGURE_ENV+=		SET_GROUP=${BINGRP}
CONFIGURE_ENV+=		SET_MODE=${BINMODE}

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
