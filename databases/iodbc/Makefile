# $NetBSD: Makefile,v 1.23 2014/01/27 06:52:27 obache Exp $

DISTNAME=	libiodbc-3.52.8
PKGNAME=	${DISTNAME:S/^lib//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iodbc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iodbc.org/dataspace/iodbc/wiki/iODBC/
COMMENT=	ODBC 3.x driver manager
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/iodbc
GNU_CONFIGURE_LIBSUBDIR=	iodbc
CONFIGURE_ARGS+=	--pkgconfigdir=${PREFIX}/lib/pkgconfig
CONFIGURE_ARGS+=	--with-iodbc-inidir=${PKG_SYSCONFDIR}

DL_AUTO_VARS=		yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/odbc.ini ${PKG_SYSCONFDIR}/odbc.ini

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/odbc.ini.sample \
		${DESTDIR}${EGDIR}/odbc.ini

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
