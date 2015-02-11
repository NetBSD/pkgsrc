# $NetBSD: Makefile,v 1.28 2015/02/11 13:29:42 pho Exp $

.include "Makefile.common"

CATEGORIES=	japanese textproc www

COMMENT=	Full-text search system for communities
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	hyperestraier.pc.in
TEST_TARGET=		check

# ${WRKSRC}/Makefile defines different targets for each non-ELF
# platforms. And for Cygwin, there is no installation target...
BROKEN_ON_PLATFORM+=	Cygwin-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Cygwin"
BUILD_TARGET=	win
TEST_TARGET=	# none
INSTALL_TARGET=	# none

.elif ${OPSYS} == "Darwin"
BUILD_TARGET=	mac
TEST_TARGET=	check-mac
INSTALL_TARGET=	install-mac

.elif ${OPSYS} == "HPUX"
BUILD_TARGET=	hpux
TEST_TARGET=	check-hpux
INSTALL_TARGET=	install-hpux
.endif

BUILDLINK_API_DEPENDS.qdbm+=	qdbm>=1.8.75

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
