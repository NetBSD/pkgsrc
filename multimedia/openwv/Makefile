# $NetBSD: Makefile,v 1.7 2026/10/13 15:31:10 ryoon Exp $

DISTNAME=	openwv-1.1.4
CATEGORIES=	multimedia
# Tarball contains Git submodule and result of `cargo vendor`.
MASTER_SITES=	https://www.ryoon.net/~ryoon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/tchebb/openwv/
COMMENT=	Open reimplementation of Google's Widevine
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_MESSAGE.etc=	Setting PKG_SYSCONFDIR
SUBST_FILES.etc+=	src/openwv.rs
SUBST_VARS.etc+=	PKG_SYSCONFDIR

SUBST_CLASSES+=		readme
SUBST_STAGE.readme=	pre-configure
SUBST_MESSAGE.readme=	Setting PREFIX for README files
SUBST_FILES.readme+=	README.firefox
SUBST_FILES.readme+=	README.chromium
SUBST_VARS.readme+=	PREFIX

INSTALLATION_DIRS+=	share/openwv
INSTALLATION_DIRS+=	share/doc/openwv

CKSUM_CRATES+=		vendor/autocxx-engine

CKSUMS+=		b8b11e4e91bf47f49fe1e43605c2c01a726aff989a4834d350f4a1b7ee94a6db
CKSUMS+=		5e0109b0f4003b1d05d44a8f3bb435a27890ca601745acd55a4721b4748fea8b

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	# Place README files
	${CP} ${FILESDIR}/README.firefox.in ${WRKSRC}/README.firefox
	${CP} ${FILESDIR}/README.chromium.in ${WRKSRC}/README.chromium

pre-configure:
	# Adjust for vendor handling of cargo.mk
	cd ${WRKSRC} && \
		${MV} vendor ..

do-install:
	${INSTALL_LIB} ${WRKSRC}/target/release/libwidevinecdm.so \
		${DESTDIR}${PREFIX}/share/openwv
	${INSTALL_DATA} ${WRKSRC}/manifest-firefox.json \
		${DESTDIR}${PREFIX}/share/openwv
	${INSTALL_DATA} ${WRKSRC}/manifest-chromium.json \
		${DESTDIR}${PREFIX}/share/openwv
	${INSTALL_DATA} ${WRKSRC}/README.firefox \
		${DESTDIR}${PREFIX}/share/doc/openwv
	${INSTALL_DATA} ${WRKSRC}/README.chromium \
		${DESTDIR}${PREFIX}/share/doc/openwv

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
