# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:24 joerg Exp $

DISTNAME=		xjump_2.7.5.orig
PKGNAME=		xjump-2.7.5
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/\
			http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/
COMMENT=		Jumping game for X

WRKSRC=			${WRKDIR}/xjump-2.7.5.orig
BUILD_TARGET=		xjump
INSTALLATION_DIRS=	bin
MAKE_ENV+=		VARBASE=${VARBASE:Q}

do-install:
	${INSTALL_GAME} ${WRKSRC}/xjump ${PREFIX}/bin/xjump

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
