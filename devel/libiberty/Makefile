# $NetBSD: Makefile,v 1.1.1.1 2004/06/02 11:28:38 shannonjr Exp $
#

DISTNAME=		libiberty-1.0
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/

MAINTAINER=		john@johnrshannon.com
COMMENT=		This package provides the GNU liberty library of "missing" functions

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/libiberty.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
