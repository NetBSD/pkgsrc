# $NetBSD: Makefile,v 1.71 2020/01/26 17:32:00 rillig Exp $

PKGNAME=	rpm2pkg-3.3.0
CATEGORIES=	pkgtools
NO_CHECKSUM=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Convert RPM archives to NetBSD packages
LICENSE=	modified-bsd

CONFLICTS+=	suse-base<=6.4

MANCOMPRESSED_IF_MANZ=	yes
USE_BSD_MAKEFILE=	yes
USE_LANGUAGES=		c99
MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

MAKE_ENV+=	FILESDIR=${FILESDIR:Q}
MAKE_FILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mclang*)
MAKE_FLAGS+=		ACTIVE_CC=clang
.endif

.include "../../mk/bsd.prefs.mk"

# using pkgsrc gcc8 fails to build with WARNS on NetBSD with:
# .../stdlib.h:115:1: error: ignoring attribute ‘pure’ in declaration of a built-in function ‘abs’ because it conflicts with attribute ‘const’ [-Werror=attributes]
.if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no" && empty(CC_VERSION:Mgcc-[89]*)
MAKE_ENV+=	WARNS=4
.else
MAKE_ENV+=	NOGCCERROR=yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
