# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:02 jlam Exp $

DISTNAME=	blitz-0.8
PKGNAME=	blitz++-0.8
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oonumerics.org/blitz/
COMMENT=	C++ template class library providing array objects

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cxx=gcc

INFO_FILES=		blitz.info

.include "../../mk/bsd.pkg.mk"
