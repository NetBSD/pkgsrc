# $NetBSD: Makefile,v 1.8 2004/04/24 22:46:09 jlam Exp $
#

DISTNAME=		libiodbc-2.50.3
PKGNAME=		iodbc-2.50.3
CATEGORIES=		databases
MASTER_SITES=		http://www.iodbc.org/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.iodbc.org/
COMMENT=		ODBC 2.x driver manager

CONFLICTS+=		unixodbc-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--with-iodbc-inidir=/etc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/iodbc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iodbc
	${INSTALL_DATA} ${WRKSRC}/odbc.ini.sample \
		${PREFIX}/share/examples/iodbc/odbc.ini
	${INSTALL_PROGRAM} ${WRKSRC}/samples/odbctest ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
