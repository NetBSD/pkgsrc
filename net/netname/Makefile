# $NetBSD: Makefile,v 1.18 2023/12/19 12:34:36 zafer Exp $
#

DISTNAME=	netname-2.2
CATEGORIES=	net
MASTER_SITES=	https://software.kimmo.suominen.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Return the canonical network name of a host

BUILD_TARGET.SunOS=	svr4
BUILD_TARGET.*=		netname

INSTALL_TARGET=	inst-all

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
