# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:28 jmmv Exp $

DISTNAME=		fbsql.c
PKGNAME=		tcl-fbsql-1.05
WRKSRC=			${WRKDIR}/src
CATEGORIES=		database
MASTER_SITES=		http://www.fastbase.co.nz/fbsql/
EXTRACT_SUFX=

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=               http://www.fastbase.co.nz/fbsql/index.html
COMMENT=		Tcl interface to MySQL

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${CP} ${_DISTDIR}/fbsql.c ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbsql.so ${PREFIX}/lib/tcl/

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
