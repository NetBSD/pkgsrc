# $NetBSD: Makefile,v 1.3 2005/01/18 21:58:55 tv Exp $
#

DISTNAME=		libiberty-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/

MAINTAINER=		john@johnrshannon.com
COMMENT=		This package provides the GNU liberty library of "missing" functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} -f ${WRKSRC}/include/ansidecl.h ${WRKSRC}/include/libiberty_decl.h

do-install:
	${INSTALL_LIB} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/libiberty_decl.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/libiberty.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
