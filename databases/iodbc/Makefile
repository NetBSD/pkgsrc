# $NetBSD: Makefile,v 1.20 2012/03/15 14:50:56 abs Exp $

DISTNAME=	libiodbc-3.52.7
PKGNAME=	${DISTNAME:S/^lib//}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/iODBC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iodbc.org/
COMMENT=	ODBC 3.x driver manager
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/iodbc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/iodbc
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
