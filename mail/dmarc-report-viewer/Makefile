# $NetBSD: Makefile,v 1.1 2026/05/28 16:13:38 ryoon Exp $

DISTNAME=	dmarc-report-viewer-2.5.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cry-inc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cry-inc/dmarc-report-viewer/
COMMENT=	Lightweight Standalone DMARC Report Viewer with IMAP Client
LICENSE=	mit

# bindgen needs libclang
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

USE_LANGUAGES=	c
USE_TOOLS+=	cmake

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"
DMARCREPV_HOME=		${VARBASE}/db/dmarcrepv

DMARCREPV_USER?=	dmarcrepv
DMARCREPV_GROUP?=	dmarcrepv

BUILD_DEFS+=		DMARCREPV_USER DMARCREPV_GROUP DMARCREPV_HOME VARBASE

PKG_GROUPS_VARS+=	DMARCREPV_GROUP
PKG_USERS_VARS+=	DMARCREPV_USER

PKG_GROUPS=		${DMARCREPV_GROUP}
PKG_USERS=		${DMARCREPV_USER}:${DMARCREPV_GROUP}

PKG_GECOS.${DMARCREPV_USER}=	DMARC report viewer
PKG_HOME.${DMARCREPV_USER}=	${DMARCREPV_HOME}
PKG_SHELL.${DMARCREPV_USER}=	${SH}

OWN_DIRS+=		${DMARCREPV_HOME}
OWN_DIRS_PERMS+=	${DMARCREPV_HOME} ${DMARCREPV_USER} ${DMARCREPV_GROUP} 0755

RCD_SCRIPTS=		dmarcrepv
FILES_SUBST+=		DMARCREPV_USER=${DMARCREPV_USER}
FILES_SUBST+=		DMARCREPV_HOME=${DMARCREPV_HOME}

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
