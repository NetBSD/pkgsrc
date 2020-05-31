# $NetBSD: Makefile,v 1.2 2020/05/31 09:51:35 nia Exp $

DISTNAME=	xxhash-0.7.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}
GITHUB_PROJECT=	xxHash
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cyan4973/xxHash
COMMENT=	Extremely fast non-cryptographic hash algorithm
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

BUILD_TARGET=	all pkgconfig

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	darwin notdarwin

.if ${OPSYS} == "Darwin"
PLIST.darwin=		yes
.else
PLIST.notdarwin=	yes
.endif

INSTALLATION_DIRS+=	bin include ${PKGMANDIR}/man1 lib lib/pkgconfig

PKGCONFIG_OVERRIDE+=	libxxhash.pc.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/xxhash.h ${DESTDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/xxhsum.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/xxhsum ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libxxhash.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libxxhash.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
.if ${OPSYS} == "Darwin"
	${INSTALL_LIB} ${WRKSRC}/libxxhash*dylib ${DESTDIR}${PREFIX}/lib
.else
	${INSTALL_LIB} ${WRKSRC}/libxxhash.so* ${DESTDIR}${PREFIX}/lib
.endif

.include "../../mk/bsd.pkg.mk"
