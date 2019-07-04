# $NetBSD: Makefile,v 1.11 2019/07/04 13:34:57 ryoon Exp $

DISTNAME=	libpaper_1.1.28
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/libp/libpaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.qa.debian.org/libp/libpaper.html
COMMENT=	Paper size handling library
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake

EGDIR=			${PREFIX}/share/examples/libpaper
CONF_FILES=		${EGDIR}/papersize ${PKG_SYSCONFDIR}/papersize

BUILD_DEFS=		PAPERSIZE

.include "../../devel/libgetopt/buildlink3.mk"

# missing generated files in 1.1.26 tarball
pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-build:
	PAPERCONF=${WRKDIR}/papersize PATH=${WRKSRC}/src:$${PATH} ${SH} \
	    ${WRKSRC}/src/paperconfig -p ${PAPERSIZE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/papersize ${DESTDIR}${EGDIR}/papersize

.include "../../mk/bsd.pkg.mk"
