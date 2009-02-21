# $NetBSD: Makefile,v 1.2 2009/02/21 16:53:33 wiz Exp $
#

DISTNAME=	libowfat-0.28
CATEGORIES=	devel
MASTER_SITES=	http://dl.fefe.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fefe.de/libowfat/
COMMENT=	Library of general purpose APIs

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake
#LICENSE=	gnu-gplv2

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
