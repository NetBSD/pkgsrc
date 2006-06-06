# $NetBSD: Makefile,v 1.12 2006/06/06 13:37:07 joerg Exp $

DISTNAME=	blitz-0.8
PKGNAME=	blitz++-0.8
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oonumerics.org/blitz/
COMMENT=	C++ template class library providing array objects

USE_LANGUAGES=		c++ fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
