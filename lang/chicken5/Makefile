# $NetBSD: Makefile,v 1.9 2023/05/04 20:54:40 nikita Exp $

.include "Makefile.common"

BUILD_DEFS+=		CHICKEN_BINARY_VERSION
CHICKEN_BINARY_VERSION=	11

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/${CHICKEN_BINARY_VERSION}

BUILD_TARGET=		all

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX}/${PKGINFODIR}
MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGNAME_NOREV}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL:Q}
MAKE_FLAGS+=	LINKER_OPTIONS=${LDFLAGS:Q}
MAKE_FLAGS+=	C_COMPILER_OPTIMIZATION_OPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	CHICKEN="${BUILDLINK_PREFIX.chicken5-boot}/libexec/chicken-bootstrap"

TEST_TARGET=	check

PLIST_SUBST+=		CHICKEN_BINARY_VERSION=${CHICKEN_BINARY_VERSION:Q}
PRINT_PLIST_AWK+=	{ sub("/${CHICKEN_BINARY_VERSION}/", "/$${CHICKEN_BINARY_VERSION}/") }
PRINT_PLIST_AWK+=	{ sub(".so.${CHICKEN_BINARY_VERSION}$$", ".so.$${CHICKEN_BINARY_VERSION}") }

# on why chicken5-boot, see this upstream ticket:
# http://bugs.call-cc.org/ticket/1776
.include "../../lang/chicken5-boot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
