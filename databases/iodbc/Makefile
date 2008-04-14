# $NetBSD: Makefile,v 1.16 2008/04/14 21:46:57 jlam Exp $

DISTNAME=	libiodbc-3.52.6
PKGNAME=	${DISTNAME:S/^lib//}
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/iODBC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iodbc.org/
COMMENT=	ODBC 3.x driver manager

CONFLICTS+=	unixodbc-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA} ${WRKSRC}/etc/odbc.ini.sample \
		${DESTDIR}${EGDIR}/odbc.ini

.include "../../mk/bsd.pkg.mk"
