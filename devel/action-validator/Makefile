# $NetBSD: Makefile,v 1.1 2024/01/18 19:28:23 schmonz Exp $

DISTNAME=		action-validator-0.5.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mpalmer/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mpalmer/action-validator/
COMMENT=		Validate GitHub Action and Workflow YAML files
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		schemastore>=0.20231122:../../textproc/schemastore

USE_LANGUAGES=		c

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	Cargo.lock Cargo.toml package.json package-lock.json
SUBST_FILES.version+=	packages/core/package.json packages/core/package-lock.json
SUBST_FILES.version+=	packages/cli/package.json packages/cli/package-lock.json
SUBST_SED.version=	-e 's|0.0.0-git|${PKGVERSION_NOREV}|g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/schemas.rs
SUBST_VARS.paths=	PREFIX

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
