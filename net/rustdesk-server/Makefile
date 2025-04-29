# $NetBSD: Makefile,v 1.1 2025/04/29 01:53:59 manu Exp $

DISTNAME=	1.1.14
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustdesk/}
GITHUB_PROJECT=	rustdesk-server
GITHUB_TAG=	refs/tags/${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

DISTFILES=	${DEFAULT_DISTFILES}

DISTFILES+=		driver.tar.gz
SITES.driver.tar.gz=	${MASTER_SITES}/hbb_common/archive/refs/tags/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rustdesk.com/
COMMENT=	Free and opensource remote desktop
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	tar

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize

RUSTDESK_USER?=		rustdesk
RUSTDESK_GROUP?=	rustdesk
PKG_USERS+=		${RUSTDESK_USER}:${RUSTDESK_GROUP}
PKG_GROUPS+=		${RUSTDESK_GROUP}
PKG_USERS_VARS+=	RUSTDESK_USER
PKG_GROUPS_VARS+=	RUSTDESK_GROUP

FILES_SUBST+=	RUSTDESK_USER=${RUSTDESK_USER:Q}
FILES_SUBST+=	RUSTDESK_GROUP=${RUSTDESK_GROUP:Q}

OWN_DIRS_PERMS+=	${VARBASE}/db/rustdesk-server \
			${RUSTDESK_USER} ${RUSTDESK_GROUP} 077

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS=			rustdesk_hbbs rustdesk_hbbr
RCD_SCRIPT_SRC.rustdesk_hbbs=	${WRKSRC}/rcd/rustdesk-hbbs
RCD_SCRIPT_SRC.rustdesk_hbbr=	${WRKSRC}/rcd/rustdesk-hbbr

.include "cargo-git-depends.mk"

post-extract:
	${CP} -R ${WRKDIR}/hbb_common-driver/* ${WRKSRC}/libs/hbb_common/
.for f in ${DISTFILES}
.  if defined(EXTRACT.${f}) && defined(VERSION.${f})
	${TAR} -xzf ${WRKDIR}/${f} -C ${WRKDIR}
	${CP} -R ${WRKDIR}/${EXTRACT.${f}} \
		${WRKDIR}/vendor/${VERSION.${f}}
	${ECHO} '{"package":null,"files":{}}' > \
    		${WRKDIR}/vendor/${VERSION.${f}}/.cargo-checksum.json
.  endif
.endfor

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
