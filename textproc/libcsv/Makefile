# $NetBSD: Makefile,v 1.2 2020/01/18 23:35:28 rillig Exp $

DISTNAME=	libcsv-3.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcsv/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://libcsv.sourceforge.net/
COMMENT=	CSV library written in pure ANSI C89
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/libcsv

.include "../../mk/bsd.pkg.mk"
