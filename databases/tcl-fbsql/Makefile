# $NetBSD: Makefile,v 1.30 2013/03/28 21:16:41 joerg Exp $

DISTNAME=		fbsql.c
PKGNAME=		tcl-fbsql-1.06
PKGREVISION=		9
CATEGORIES=		databases
MASTER_SITES=		http://www.fastbase.co.nz/fbsql/
EXTRACT_SUFX=

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.fastbase.co.nz/fbsql/index.html
COMMENT=		Tcl interface to MySQL

WRKSRC=			${WRKDIR}/src
USE_LIBTOOL=		YES
DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	lib/tcl

MAKE_ENV+=	MYSQLLIBDIR=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
MAKE_ENV+=	MYSQLINCDIR=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${CP} ${_DISTDIR}/fbsql.c ${WRKSRC}/

do-install:
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/fbsql.la ${DESTDIR}${PREFIX}/lib/tcl

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
