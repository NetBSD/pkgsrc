# $NetBSD: Makefile,v 1.8 2005/09/05 14:06:59 adam Exp $

DISTNAME=	blitz-0.8
PKGNAME=	blitz++-0.8
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oonumerics.org/blitz/
COMMENT=	C++ template class library providing array objects

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cxx=gcc

INFO_FILES=		blitz.info

.include "../../mk/bsd.pkg.mk"
