# $NetBSD: Makefile,v 1.15 2008/02/09 07:26:57 adam Exp $

DISTNAME=	libiodbc-3.52.6
PKGNAME=	${DISTNAME:S/^lib//}
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/iODBC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iodbc.org/
COMMENT=	ODBC 3.x driver manager

CONFLICTS+=	unixodbc-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--with-iodbc-inidir=${PKG_SYSCONFDIR}
LIBADD_DL=		${DL_LDFLAGS} ${DL_LIBS}
MAKE_FLAGS+=		LIBADD_DL=${LIBADD_DL:Q}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/odbc.ini ${PKG_SYSCONFDIR}/odbc.ini

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/odbc.ini.sample ${EGDIR}/odbc.ini

.include "../../mk/bsd.pkg.mk"
