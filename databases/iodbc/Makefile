# $NetBSD: Makefile,v 1.1.1.1 1999/07/15 06:25:04 jlam Exp $
#

DISTNAME=		libiodbc-2.50.3
PKGNAME=		iodbc-2.50.3
CATEGORIES=		databases
MASTER_SITES=		http://www.iodbc.org/dist/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.iodbc.org/

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-iodbc-inidir=/etc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iodbc
	${INSTALL_DATA} ${WRKSRC}/odbc.ini.sample \
		${PREFIX}/share/examples/iodbc/odbc.ini

.include "../../mk/bsd.pkg.mk"
