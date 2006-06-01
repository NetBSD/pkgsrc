# $NetBSD: Makefile,v 1.32 2006/06/01 21:55:28 joerg Exp $

DISTNAME=       top-3.6alpha7
PKGNAME=	top-3.6a7
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

GNU_CONFIGURE=		yes

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
