# $NetBSD: Makefile,v 1.12 2004/03/12 22:18:46 minskim Exp $

DISTNAME=		fbsql.c
PKGNAME=		tcl-fbsql-1.05
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.fastbase.co.nz/fbsql/
EXTRACT_SUFX=

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=               http://www.fastbase.co.nz/fbsql/index.html
COMMENT=		Tcl interface to MySQL

WRKSRC=			${WRKDIR}/src
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
DIST_SUBDIR=		${PKGNAME_NOREV}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${CP} ${_DISTDIR}/fbsql.c ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbsql.so ${PREFIX}/lib/tcl

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
