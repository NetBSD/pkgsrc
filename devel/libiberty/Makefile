# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:45 joerg Exp $
#

DISTNAME=		libiberty-1.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/

MAINTAINER=		john@johnrshannon.com
COMMENT=		This package provides the GNU liberty library of "missing" functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} -f ${WRKSRC}/include/ansidecl.h ${WRKSRC}/include/libiberty_decl.h

do-install:
	${INSTALL_LIB} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/libiberty_decl.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/libiberty.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
