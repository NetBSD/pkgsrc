# $NetBSD: Makefile,v 1.17 2024/05/31 10:38:11 nikita Exp $

GITHUB_PROJECT=	gleam
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gleam-1.2.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=gleam-lang/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gleam-lang/gleam/
COMMENT=	ML-flavoured type-safe language using the BEAM runtime
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gleam-${PKGVERSION_NOREV}

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gleam ${DESTDIR}${PREFIX}/bin

do-test:
	if ${TEST} -x "${DESTDIR}${PREFIX}/bin/gleam"; then \
		if ${TEST} -d "${WRKSRC}/hello"; then \
			cd ${WRKSRC}/hello && ${DESTDIR}${PREFIX}/bin/gleam test; \
		else \
			cd ${WRKSRC} && ${DESTDIR}${PREFIX}/bin/gleam new hello && cd hello && ${DESTDIR}${PREFIX}/bin/gleam test; \
		fi; \
	else \
		if ${TEST} -d "${WRKSRC}/hello"; then \
			cd ${WRKSRC}/hello && ${WRKSRC}/target/release/gleam test; \
		else \
			cd ${WRKSRC} && ${WRKSRC}/target/release/gleam new hello && cd hello && ${WRKSRC}/target/release/gleam test; \
		fi; \
	fi

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
