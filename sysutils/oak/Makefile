# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:16 wiz Exp $
#

DISTNAME=		oak-1.5.0
CATEGORIES=		sysutils
MASTER_SITES=		https://www.ktools.org/dist/oak/

MAINTAINER=		jdw-pkgsrc@menelos.com
HOMEPAGE=		https://www.ktools.org/dist/oak/
COMMENT=		System log reporting tool

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=

RCD_SCRIPTS=		oak
CONF_FILES=		${PREFIX}/share/examples/oak/oak.conf ${PKG_SYSCONFDIR}/oak.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/oak

post-install:
	${INSTALL_DATA}	${FILESDIR}/oak.conf* ${DESTDIR}${PREFIX}/share/examples/oak/
	${INSTALL_DATA} ${FILESDIR}/oak.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
