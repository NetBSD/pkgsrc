# $NetBSD: Makefile,v 1.33 2007/02/22 19:27:12 wiz Exp $

DISTNAME=	top-3.6alpha7
PKGNAME=	top-3.6a7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

GNU_CONFIGURE=		yes

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
