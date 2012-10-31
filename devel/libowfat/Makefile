# $NetBSD: Makefile,v 1.5 2012/10/31 11:17:19 asau Exp $
#

DISTNAME=	libowfat-0.28
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dl.fefe.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fefe.de/libowfat/
COMMENT=	Library of general purpose APIs
LICENSE=	gnu-gpl-v2

CONFLICTS=	libtai-[0-9]*

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
