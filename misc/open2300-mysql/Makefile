# $NetBSD: Makefile,v 1.1.1.1 2004/11/10 08:21:21 martin Exp $
#

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	WS 23xx weather station MySQL support

PATCHDIR=	${.CURDIR}/../open2300/patches
DISTINFO_FILE=	${.CURDIR}/../open2300/distinfo

ALL_TARGET=	mysql2300
INSTALL_TARGET=	install-mysql

USE_BUILDLINK3=yes

.include "../../mk/mysql.buildlink3.mk"
.include "../open2300/Makefile.common"
