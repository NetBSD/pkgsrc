# $NetBSD: Makefile,v 1.18 2005/06/16 06:57:44 jlam Exp $

DISTNAME=		fbsql.c
PKGNAME=		tcl-fbsql-1.06
PKGREVISION=	1
CATEGORIES=		databases
MASTER_SITES=		http://www.fastbase.co.nz/fbsql/
EXTRACT_SUFX=

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=               http://www.fastbase.co.nz/fbsql/index.html
COMMENT=		Tcl interface to MySQL

WRKSRC=			${WRKDIR}/src
USE_LIBTOOL=		YES
DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	lib/tcl

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${CP} ${_DISTDIR}/fbsql.c ${WRKSRC}/

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbsql.so ${PREFIX}/lib/tcl

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
