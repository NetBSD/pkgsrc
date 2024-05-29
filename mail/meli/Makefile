# $NetBSD: Makefile,v 1.18 2024/05/29 16:33:22 adam Exp $

DISTNAME=	v0.8.4
PKGNAME=	${DISTNAME:S|^v|meli-|}
PKGREVISION=	2
CATEGORIES=	mail news
DIST_SUBDIR=	${PKGNAME_NOREV}
MASTER_SITES=	https://git.meli-email.org/meli/meli/archive/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://meli-email.org/
COMMENT=	Terminal mail client
LICENSE=	gnu-gpl-v3

# ring-v0.16.20 does not support these archs
BROKEN_ON_PLATFORM=	*-*-powerpc64 *-*-sparc64
# error[E0308]: mismatched types
ONLY_FOR_PLATFORM=	${LP64PLATFORMS}

USE_TOOLS+=	pax pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES=			cli-docs jmap regexp smtp text-processing

.include "options.mk"
.include "cargo-depends.mk"

PKG_DOCS=	meli/docs/external-tools.md meli/docs/mail.vim
DOCDIR=		share/doc/${PKGBASE}

WRKSRC=	${WRKDIR}/meli

MAKE_ENV+=	OPENSSL_DIR=${SSLBASE:Q}

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib
RUSTFLAGS+=	-C link-arg=-L${SSLBASE}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${X11BASE}/lib
RUSTFLAGS+=	-C link-arg=-L${X11BASE}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=-L${PREFIX}/lib

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7 ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/meli	\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/meli/docs/meli.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/meli.1
	${INSTALL_MAN} ${WRKSRC}/meli/docs/meli.7		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/meli.7
	${INSTALL_MAN} ${WRKSRC}/meli/docs/meli-themes.5	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/meli-themes.5
	${INSTALL_MAN} ${WRKSRC}/meli/docs/meli.conf.5		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/meli.conf.5

post-install:
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}		\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc		\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${RUN}cd ${WRKSRC}/meli/docs &&				\
		${PAX} -rw -pm samples ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"

.include "../../mk/bsd.pkg.mk"
