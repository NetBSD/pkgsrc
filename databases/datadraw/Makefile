# $NetBSD: Makefile,v 1.8 2026/08/04 20:28:48 wiz Exp $
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
