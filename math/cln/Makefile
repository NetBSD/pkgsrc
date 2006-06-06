# $NetBSD: Makefile,v 1.13 2006/06/06 14:56:20 joerg Exp $

DISTNAME=	cln-1.1.11
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE+=	libtool
PKGCONFIG_OVERRIDE=	cln.pc.in
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
