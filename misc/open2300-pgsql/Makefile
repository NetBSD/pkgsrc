# $NetBSD: Makefile,v 1.1 2022/09/06 15:56:53 martin Exp $
#

PKGNAME=	${DISTNAME:S/-/-pgsql-/}
COMMENT=	WS 23xx weather station PostgesSQL support
LICENSE=	gnu-gpl-v2

BUILD_TARGET=		pgsql2300
INSTALL_TARGET=		install-pgsql
INSTALLATION_DIRS+=	bin

#LIBS+=		-lmysqlclient
#LIBS.SunOS+=	-lnsl -lsocket
#MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../misc/open2300/Makefile.common"
