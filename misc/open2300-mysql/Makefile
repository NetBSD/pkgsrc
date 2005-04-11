# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:38 tv Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	WS 23xx weather station MySQL support

PATCHDIR=	${.CURDIR}/../open2300/patches
DISTINFO_FILE=	${.CURDIR}/../open2300/distinfo

BUILD_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql


.include "../../mk/mysql.buildlink3.mk"
.include "../open2300/Makefile.common"
