# $NetBSD: Makefile,v 1.18 2023/07/05 22:14:28 wiz Exp $

DISTNAME=	libpaper-2.1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=rrthomas/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/libpaper
COMMENT=	Paper size handling library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/libpaper
CONF_FILES+=		${EGDIR}/papersize ${PKG_SYSCONFDIR}/papersize
CONF_FILES+=		${EGDIR}/paperspecs ${PKG_SYSCONFDIR}/paperspecs
INSTALLATION_DIRS=	${EGDIR}

BUILD_DEFS=		PAPERSIZE

post-build:
	${ECHO} ${PAPERSIZE} > ${WRKDIR}/papersize

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/paperspecs ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/papersize ${DESTDIR}${EGDIR}/papersize

.include "../../mk/bsd.pkg.mk"
