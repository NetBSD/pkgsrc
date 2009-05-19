# $NetBSD: Makefile,v 1.3 2009/05/19 08:59:10 wiz Exp $
#

DISTNAME=	libowfat-0.28
CATEGORIES=	devel
MASTER_SITES=	http://dl.fefe.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fefe.de/libowfat/
COMMENT=	Library of general purpose APIs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
