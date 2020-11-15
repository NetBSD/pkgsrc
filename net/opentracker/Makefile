# $NetBSD: Makefile,v 1.2 2020/11/15 10:29:04 wiz Exp $

DISTNAME=	opentracker-0.0.20180526
CATEGORIES=	net
MASTER_SITES=	# https://erdgeist.org/gitweb/opentracker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erdgeist.org/arts/software/opentracker/
COMMENT=	Bittorrent tracker
LICENSE=	beer-ware

MAKE_FLAGS+=	LIBOWFAT_HEADERS=${PREFIX}/include/libowfat
MAKE_FLAGS+=	LIBOWFAT_LIBRARY=${PREFIX}/lib
MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
# turn on IPv6-only support
#MAKE_FLAGS+=	-DWANT_V6

INSTALLATION_DIRS+=	bin

WRKSRC=	${WRKDIR}/opentracker

.include "../../devel/libowfat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
