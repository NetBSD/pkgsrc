# $NetBSD: Makefile,v 1.10 2010/02/05 15:27:27 martin Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	WS 23xx weather station MySQL support
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql

LIBS+=		-lmysqlclient
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/mysql.buildlink3.mk"
.include "../../misc/open2300/Makefile.common"
