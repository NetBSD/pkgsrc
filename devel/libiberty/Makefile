# $NetBSD: Makefile,v 1.2 2004/06/05 16:32:02 minskim Exp $
#

DISTNAME=		libiberty-1.0
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/

MAINTAINER=		john@johnrshannon.com
COMMENT=		This package provides the GNU liberty library of "missing" functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/libiberty.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
