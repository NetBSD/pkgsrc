# $NetBSD: Makefile,v 1.1.1.1 2009/11/25 22:42:35 dmcmahill Exp $
#

DISTNAME=	datadraw3.1.1
PKGNAME=	datadraw-3.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=datadraw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datadraw.sourceforge.net/
COMMENT=	Persistent database generator for high performance C applications

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:Q}
USE_TOOLS+=		bash:build bison flex gmake
CONFIG_SHELL=		${TOOLS_PATH.bash}

BUILD_TARGET=	datadraw

.include "../../mk/bsd.pkg.mk"
