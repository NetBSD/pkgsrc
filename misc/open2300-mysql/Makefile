# $NetBSD: Makefile,v 1.17 2021/06/23 20:33:13 nia Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
PKGREVISION=	4
COMMENT=	WS 23xx weather station MySQL support
LICENSE=	gnu-gpl-v2

BUILD_TARGET=		mysql2300
INSTALL_TARGET=		install-mysql
INSTALLATION_DIRS+=	bin

LIBS+=		-lmysqlclient
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/mysql.buildlink3.mk"
.include "../../misc/open2300/Makefile.common"
