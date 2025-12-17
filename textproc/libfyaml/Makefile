# $NetBSD: Makefile,v 1.5 2025/12/17 23:10:06 nia Exp $

DISTNAME=	libfyaml-0.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	bash:test m4
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libfyaml.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS" && ${OPSYS} != "Linux"
SUBST_CLASSES+=		alloca
SUBST_STAGE.alloca=	pre-configure
SUBST_MESSAGE.alloca=	Changing alloca.h to stdlib.h.
SUBST_FILES.alloca+=	src/blake3/blake3_backend.c
SUBST_FILES.alloca+=	src/blake3/blake3_be_cpusimd.c
SUBST_FILES.alloca+=	src/blake3/blake3_host_state.c
SUBST_FILES.alloca+=	src/blake3/blake3.c
SUBST_FILES.alloca+=	src/blake3/fy-blake3.c
SUBST_FILES.alloca+=	src/internal/fy-b3sum.c
SUBST_FILES.alloca+=	src/internal/fy-thread.c
SUBST_FILES.alloca+=	src/thread/fy-thread.c
SUBST_FILES.alloca+=	src/util/fy-utf8.h
SUBST_FILES.alloca+=	test/libfyaml-test-private-id.c
SUBST_SED.alloca=	-e 's,alloca.h,stdlib.h,'
.endif

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
