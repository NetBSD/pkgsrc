# $NetBSD: Makefile,v 1.1.1.1 2003/04/30 00:03:34 jtb Exp $

DISTNAME=		blitz-0.6
PKGNAME=		blitz++-0.6
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.oonumerics.org/blitz/
COMMENT=		C++ template class library providing array objects

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS+=	--with-cxx=gcc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/blitz
	${INSTALL_DATA} ${WRKSRC}/manual/blitz.ps ${PREFIX}/share/doc/blitz

.include "../../mk/bsd.pkg.mk"
