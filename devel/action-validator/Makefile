# $NetBSD: Makefile,v 1.3 2025/06/19 20:20:18 wiz Exp $

DISTNAME=		action-validator-0.6.0.20250215
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mpalmer/}
#GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_TAG=		2f8be1d2066eb3687496a156d00b4f1b3ea7b028

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mpalmer/action-validator/
COMMENT=		Validate GitHub Action and Workflow YAML files
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		schemastore>=0.20231122:../../textproc/schemastore

USE_LANGUAGES=		c

RUST_REQ=		1.60.0

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	Cargo.lock Cargo.toml package.json package-lock.json
SUBST_FILES.version+=	packages/core/package.json packages/core/package-lock.json
SUBST_FILES.version+=	packages/cli/package.json packages/cli/package-lock.json
# TODO: adapt to use ${PKGVERSION_NOREV} after 0.6.1+
SUBST_SED.version=	-e 's|0.0.0-git|0.6.0|g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/schemas.rs
SUBST_VARS.paths=	PREFIX

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
