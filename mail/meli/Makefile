# $NetBSD: Makefile,v 1.6 2023/02/21 13:29:15 pin Exp $

DISTNAME=	alpha-0.7.2
PKGNAME=	meli-0.7.2
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	https://git.meli.delivery/meli/meli/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://meli.delivery/
COMMENT=	Terminal mail client
LICENSE=	gnu-gpl-v3

# Possibly working on other 64-bit processors but, not tested
ONLY_FOR_PLATFORM=	*-*-x86_64

TOOL_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/meli

USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/meli ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/meli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/meli.1
	${INSTALL_MAN} ${WRKSRC}/docs/meli-themes.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/meli-themes.5
	${INSTALL_MAN} ${WRKSRC}/docs/meli.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/meli.conf.5

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mail/notmuch/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
