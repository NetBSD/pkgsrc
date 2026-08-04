# $NetBSD: Makefile,v 1.20 2026/08/04 20:29:02 wiz Exp $

DISTNAME=	bacisrc
PKGNAME=	baci-20000725
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTFILES=	bacisrc.tar.gz \
		bacidoc.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://inside.mines.edu/~tcamp/baci/baci_index.html
COMMENT=	Ben-Ari Concurrent Interpreter

USE_TOOLS+=	flex bison:run

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/ccomp && ${MAKE}
	cd ${WRKSRC}/disasm && ${MAKE}
	cd ${WRKSRC}/interp && ${MAKE}
	cd ${WRKSRC}/pascomp && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccomp/bacc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/disasm/badis ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/interp/bainterp ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pascomp/bapas ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/baci
	${INSTALL_DATA} ${WRKDIR}/bacidoc/* ${DESTDIR}${PREFIX}/share/doc/baci

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
