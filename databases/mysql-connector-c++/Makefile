# $NetBSD: Makefile,v 1.11 2025/01/31 13:30:15 wiz Exp $

DISTNAME=	mysql-connector-c++-9.2.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	databases
MASTER_SITES=	https://dev.mysql.com/get/Downloads/Connector-C++/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/cpp/
COMMENT=	Standardized MySQL database driver for C++ development
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

post-install:
	${RM} ${DESTDIR}${PREFIX}/INFO_BIN
	${RM} ${DESTDIR}${PREFIX}/INFO_SRC

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
