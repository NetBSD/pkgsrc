# $NetBSD: Makefile,v 1.5 2003/04/18 13:16:41 jmc Exp $

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
	@-${MKDIR} ${TCL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/fbsql.so ${TCL_DIR}

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.ifmake do-install
# Need here for $PREFIX
TCL_DIR!=		. ${PREFIX}/lib/tclConfig.sh; echo $$TCL_PACKAGE_PATH
.endif
