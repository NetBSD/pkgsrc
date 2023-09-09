# $NetBSD: Makefile,v 1.2 2023/09/09 20:16:41 pin Exp $

DISTNAME=	eza-0.11.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eza-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eza-community/eza/
COMMENT=	Modern, maintained replacement for ls
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-build:
	${CP} ${FILESDIR}/eza.1 ${WRKDIR}/eza.1
	${CP} ${FILESDIR}/eza_colors-explanation.5 ${WRKDIR}/eza_colors-explanation.5
	${CP} ${FILESDIR}/eza_colors.5 ${WRKDIR}/eza_colors.5

post-install:
	${INSTALL_MAN} ${WRKDIR}/eza.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/eza_colors-explanation.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKDIR}/eza_colors.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
