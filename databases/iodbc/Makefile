# $NetBSD: Makefile,v 1.3 2000/08/14 15:07:27 wiz Exp $
#

DISTNAME=		libiodbc-2.50.3
PKGNAME=		iodbc-2.50.3
CATEGORIES=		databases
MASTER_SITES=		http://www.iodbc.org/dist/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.iodbc.org/

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

.include "../../mk/bsd.pkg.mk"
