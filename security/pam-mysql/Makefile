# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:46 joerg Exp $

DISTNAME=	pam_mysql-0.5
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pam-mysql/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pam-mysql.sourceforge.net/
COMMENT=	PAM module for authenticating with MySQL

WRKSRC=		${WRKDIR}/pam_mysql
DOCDIR=		${PREFIX}/share/doc/pam-mysql

INSTALLATION_DIRS=	lib

do-build:
	${CC} -fpic -DPIC -Wall -I${LOCALBASE}/include \
		-c ${WRKSRC}/pam_mysql.c -o ${WRKSRC}/pam_mysql.o
	${LD} -x --shared -o ${WRKSRC}/pam_mysql.so ${WRKSRC}/pam_mysql.o \
		-lpam -lcrypt -L${LOCALBASE}/lib/mysql \
		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql -lmysqlclient \
		-L${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/pam_mysql.so ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme ${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
