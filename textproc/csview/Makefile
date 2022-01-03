# $NetBSD: Makefile,v 1.6 2022/01/03 17:30:30 pin Exp $

DISTNAME=	csview-0.3.12
# Do not update this pkg, v1.0.0 requires the Nightly Rust compiler
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wfxr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wfxr/csview/
COMMENT=	High performance csv viewer with cjk/emoji support
LICENSE=	apache-2.0

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
PRETTYTABLE-RS_REV=	3239b51dbbb449e69cd599b83bfb152441209cc3
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		prettytable-rs-${PRETTYTABLE-RS_REV}.tar.gz
SITES.prettytable-rs-${PRETTYTABLE-RS_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=wfxr/}prettytable-rs/archive/${PRETTYTABLE-RS_REV}.tar.gz

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

post-extract:
	mv ${WRKDIR}/prettytable-rs-* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/csview ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
