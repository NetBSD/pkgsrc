# $NetBSD: Makefile,v 1.81 2026/01/27 08:40:20 wiz Exp $
#

DISTNAME=	gkrellm-multiping-2.0.15
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmakovicka/}
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jmakovicka/gkrellm-multiping
COMMENT=	Pings several machines and prints out stats
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}
MAKE_FLAGS+=	INSTALL_LIB=${INSTALL_LIB:Q}
MAKE_FLAGS+=	INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}
MAKE_FLAGS+=	HELPER_DIR=${PREFIX:Q}/libexec
MAKE_FLAGS+=	PLUGIN_DIR=${PREFIX:Q}/lib/gkrellm2/plugins
MAKE_FLAGS+=	VERSION=${PKGVERSION:Q}

SPECIAL_PERMS+=	libexec/pinger ${SETUID_ROOT_PERMS}

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
