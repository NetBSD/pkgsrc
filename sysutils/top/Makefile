# $NetBSD: Makefile,v 1.35 2008/04/06 12:21:05 heinz Exp $

DISTNAME=	top-3.6.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
