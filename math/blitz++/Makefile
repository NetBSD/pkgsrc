# $NetBSD: Makefile,v 1.4 2004/01/24 13:58:23 grant Exp $

DISTNAME=		blitz-0.6
PKGNAME=		blitz++-0.6
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.oonumerics.org/blitz/
COMMENT=		C++ template class library providing array objects

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-cxx=gcc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/blitz
	${INSTALL_DATA} ${WRKSRC}/manual/blitz.ps ${PREFIX}/share/doc/blitz

.include "../../mk/bsd.pkg.mk"
