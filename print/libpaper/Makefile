# $NetBSD: Makefile,v 1.20 2023/11/09 18:58:02 nia Exp $

DISTNAME=	libpaper-2.1.2
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
USE_FEATURES+=		getline strndup strnlen

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
