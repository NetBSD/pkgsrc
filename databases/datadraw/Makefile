# $NetBSD: Makefile,v 1.5 2020/01/18 23:30:17 rillig Exp $
#

DISTNAME=	datadraw3.1.1
PKGNAME=	datadraw-3.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=datadraw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://datadraw.sourceforge.net/
COMMENT=	Persistent database generator for high performance C applications

LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:Q}
USE_TOOLS+=		bash:build bison flex gmake
CONFIG_SHELL=		${TOOLS_PATH.bash}

BUILD_TARGET=	datadraw

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
