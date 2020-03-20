# $NetBSD: Makefile,v 1.3 2020/03/20 11:58:27 nia Exp $

DISTNAME=	libcsv-3.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcsv/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://libcsv.sourceforge.net/
COMMENT=	CSV library written in pure ANSI C89
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/libcsv

.include "../../mk/bsd.pkg.mk"
