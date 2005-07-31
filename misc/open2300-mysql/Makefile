# $NetBSD: Makefile,v 1.5 2005/07/31 14:03:28 grant Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	WS 23xx weather station MySQL support

PATCHDIR=	${.CURDIR}/../open2300/patches
DISTINFO_FILE=	${.CURDIR}/../open2300/distinfo

BUILD_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql

LIBS+=		-lmysqlclient
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:Q}

.include "../../mk/mysql.buildlink3.mk"
.include "../open2300/Makefile.common"
