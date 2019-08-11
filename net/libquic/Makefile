# $NetBSD: Makefile,v 1.9 2019/08/11 13:22:10 wiz Exp $

DISTNAME=	libquic-0.0.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=devsisters/}
GITHUB_TAG=	v0.0.3-6e3a05d

MAINTAINER=	agc@NetBSD.org
COMMENT=	Multiplexed stream transport over UDP
LICENSE=	modified-bsd

.include "../../lang/go/version.mk"
BUILD_DEPENDS+=		${GO_PACKAGE_DEP}

SUBST_CLASSES+=		path go
SUBST_STAGE.link=	pre-configure
SUBST_MESSAGE.link=	Fix paths
SUBST_FILES.link=	src/base/base_paths_posix.cc
SUBST_SED.link=		-e 's|@PREFIX@|'${PREFIX}'|'
SUBST_STAGE.go=		pre-configure
SUBST_FILES.go=		boringssl/CMakeLists.txt
SUBST_SED.go=		-e '/find_program.GO_EXECUTABLE/s,go,${GO},'

USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake gmake perl

AUTO_MKDIRS=	yes

pre-build:
	mkdir -p ${WRKSRC}/build

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} cmake -DCMAKE_BUILD_TYPE=Release ..
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} gmake

INSTLIBS+=	build/boringssl/crypto/libcrypto.a
INSTLIBS+=	build/boringssl/ssl/libssl.a
INSTLIBS+=	build/boringssl/decrepit/libdecrepit.a
INSTLIBS+=	build/protobuf/libprotobuf.a
INSTLIBS+=	build/libquic.a

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/quic/lib
	for f in ${INSTLIBS}; do					\
		${INSTALL_LIB} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/quic/lib/; \
	done

.include "../../mk/bsd.pkg.mk"
