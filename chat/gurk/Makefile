# $NetBSD: Makefile,v 1.4 2026/04/30 08:36:58 wiz Exp $

DISTNAME=	gurk-rs-0.9.3
PKGNAME=	${DISTNAME:S/-rs//}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=boxdot/}
GITHUB_PROJECT=	gurk-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boxdot/gurk-rs/
COMMENT=	Signal Messenger client for terminal
LICENSE=	gnu-agpl-v3

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake perl

WRKSRC=		${WRKDIR}/${DISTNAME}

# Depends on an unpublished crates. Can't use cargo.mk to fetch it.
CURVE25519-DALEK_REV=		7c6d34756355a3566a704da84dce7b1c039a6572
LIBSQLITE3-SYS_REV=		d4523ff6cdb6472db55789ae92d518989ee8bfd6
LIBSIGNAL_REV=			8418be45dba3ebc17127b5c6b76ce02886350524
LIBSIGNAL-SERVICE-RS_REV=	782c0d6bf0c4a6ab52f98d7b6d950a13f28f3020
POKSHO_REV=			e46841ea2c1ad03bc5113eba267ac1543689d031
PRESAGE_REV=			600c4ede51865f7de6ca21507e738a7bd70cc7ae
SPQR_REV=			f2589fef855c10f39d72634dab3d14654dd410bf
SQLX_REV=			53c3a26c1b484175f3beb21853a1061b488bf7af

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	curve25519-dalek-${CURVE25519-DALEK_REV}.tar.gz
DISTFILES+=	libsignal-service-rs-${LIBSIGNAL-SERVICE-RS_REV}.tar.gz
DISTFILES+=	libsignal-${LIBSIGNAL_REV}.tar.gz
DISTFILES+=	libsqlite3-sys-${LIBSQLITE3-SYS_REV}.tar.gz
DISTFILES+=	poksho-${POKSHO_REV}.tar.gz
DISTFILES+=	presage-${PRESAGE_REV}.tar.gz
DISTFILES+=	spqr-${SPQR_REV}.tar.gz
DISTFILES+=	sqlx-${SQLX_REV}.tar.gz

SITES.curve25519-dalek-${CURVE25519-DALEK_REV}.tar.gz=		-${MASTER_SITE_GITHUB:=signalapp/}curve25519-dalek/archive/${CURVE25519-DALEK_REV}.tar.gz
SITES.libsignal-service-rs-${LIBSIGNAL-SERVICE-RS_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=whisperfish/}libsignal-service-rs/archive/${LIBSIGNAL-SERVICE-RS_REV}.tar.gz
SITES.libsignal-${LIBSIGNAL_REV}.tar.gz=			-${MASTER_SITE_GITHUB:=signalapp/}libsignal/archive/${LIBSIGNAL_REV}.tar.gz
SITES.libsqlite3-sys-${LIBSQLITE3-SYS_REV}.tar.gz=		-${MASTER_SITE_GITHUB:=boxdot/}rusqlite/archive/${LIBSQLITE3-SYS_REV}.tar.gz
SITES.poksho-${POKSHO_REV}.tar.gz=				-${MASTER_SITE_GITHUB:=signalapp/}libsignal/archive/${POKSHO_REV}.tar.gz
SITES.presage-${PRESAGE_REV}.tar.gz=				-${MASTER_SITE_GITHUB:=whisperfish/}presage/archive/${PRESAGE_REV}.tar.gz
SITES.spqr-${SPQR_REV}.tar.gz=					-${MASTER_SITE_GITHUB:=signalapp/}SparsePostQuantumRatchet/archive/${SPQR_REV}.tar.gz
SITES.sqlx-${SQLX_REV}.tar.gz=					-${MASTER_SITE_GITHUB:=gferon/}sqlx/archive/${SQLX_REV}.tar.gz

INSTALLATION_DIRS+=	share/doc/gurk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/gurk

.include "cargo-depends.mk"

# See https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
