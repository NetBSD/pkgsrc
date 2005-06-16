# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:56 jlam Exp $

DISTNAME=		xjump_2.7.5.orig
PKGNAME=		xjump-2.7.5
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/\
			http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/
COMMENT=		Jumping game for X

WRKSRC=			${WRKDIR}/xjump-2.7.5.orig
BUILD_TARGET=		xjump
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL} -g games -m 2755 ${WRKSRC}/xjump ${PREFIX}/bin/xjump

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
