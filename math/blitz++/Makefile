# $NetBSD: Makefile,v 1.5 2004/04/11 09:02:04 snj Exp $

DISTNAME=		blitz-0.6
PKGNAME=		blitz++-0.6
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.oonumerics.org/blitz/
COMMENT=		C++ template class library providing array objects

CONFIGURE_ARGS+=	--with-cxx=gcc
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/blitz
	${INSTALL_DATA} ${WRKSRC}/manual/blitz.ps ${PREFIX}/share/doc/blitz

.include "../../mk/bsd.pkg.mk"
