# $NetBSD: Makefile,v 1.3 2026/01/23 07:28:05 kikadf Exp $

DISTNAME=	openwv-1.1.3
PKGREVISION=	1
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

post-extract:
	# Adjust for vendor handling of cargo.mk
	cd ${WRKSRC} && \
		${MV} vendor ..
	# Place README files
	${CP} ${FILESDIR}/README.firefox.in ${WRKSRC}/README.firefox
	${CP} ${FILESDIR}/README.chromium.in ${WRKSRC}/README.chromium

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
