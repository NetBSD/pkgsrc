# $NetBSD: Makefile,v 1.66 2015/10/11 10:56:44 tron Exp $

PKGNAME=	rpm2pkg-3.2.3
CATEGORIES=	pkgtools
NO_CHECKSUM=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
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

.if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no"
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
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
