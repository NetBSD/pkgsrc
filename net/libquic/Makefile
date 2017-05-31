# $NetBSD: Makefile,v 1.3 2017/05/31 23:17:26 agc Exp $

DISTNAME=	libquic-0.0.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=devsisters/}
GITHUB_TAG=	v0.0.3-6e3a05d

MAINTAINER=	agc@NetBSD.org
COMMENT=	Multiplexed stream transport over UDP
LICENSE=	modified-bsd

DEPENDS+=		go-[0-9]*:../../lang/go

SUBST_CLASSES+=		path
SUBST_STAGE.link=	post-patch
SUBST_MESSAGE.link=	Fix paths
SUBST_FILES.link=	src/base/base_paths_posix.cc
SUBST_SED.link=		-e 's|@PREFIX@|'${PREFIX}'|'

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
