# $NetBSD: Makefile,v 1.10 2019/02/13 20:21:37 wiz Exp $

DISTNAME=	libpaper_1.1.26
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/libp/libpaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/libs/libpaper1
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
