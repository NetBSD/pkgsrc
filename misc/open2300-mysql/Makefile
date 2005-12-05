# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:40 rillig Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	WS 23xx weather station MySQL support

PATCHDIR=	${.CURDIR}/../open2300/patches
DISTINFO_FILE=	${.CURDIR}/../open2300/distinfo

BUILD_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql

LIBS+=		-lmysqlclient
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/mysql.buildlink3.mk"
.include "../../misc/open2300/Makefile.common"
