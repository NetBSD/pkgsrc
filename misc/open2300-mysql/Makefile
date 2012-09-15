# $NetBSD: Makefile,v 1.13 2012/09/15 15:03:24 obache Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
PKGREVISION=	2
COMMENT=	WS 23xx weather station MySQL support
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql
INSTALLATION_DIRS+=	bin

LIBS+=		-lmysqlclient
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/mysql.buildlink3.mk"
.include "../../misc/open2300/Makefile.common"
