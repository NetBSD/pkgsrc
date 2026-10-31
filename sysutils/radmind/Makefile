# $NetBSD: Makefile,v 1.49 2026/10/31 23:23:53 hauke Exp $

DISTNAME=	radmind-1.15.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=radmind/}
GITHUB_PROJECT=	radmind
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/Radmind/
COMMENT=	Remote file administration and integrity tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-radminddir=${RADMINDDIR}
CONFIGURE_ENV+=		diffpath=${TOOLS_DIFF:Q}

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

.include "../../mk/compiler.mk"

BUILD_TARGET=		all man rash
RADMINDDIR=		${VARBASE}/radmind
BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		radmind

OWN_DIRS_PERMS+=	${RADMINDDIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/cert ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
OWN_DIRS_PERMS+=	${RADMINDDIR}/client ${REAL_ROOT_USER} \
			${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/preapply ${REAL_ROOT_USER} \
			${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/postapply ${REAL_ROOT_USER} \
			${REAL_ROOT_GROUP} 0750

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
