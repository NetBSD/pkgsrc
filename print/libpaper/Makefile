# $NetBSD: Makefile,v 1.7 2010/04/23 12:45:01 jmmv Exp $
#

DISTNAME=	libpaper_1.1.23
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/libp/libpaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/libs/libpaper1
COMMENT=	Paper size handling library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/libpaper
CONF_FILES=		${EGDIR}/papersize ${PKG_SYSCONFDIR}/papersize

BUILD_DEFS=		PAPERSIZE

.include "../../devel/libgetopt/buildlink3.mk"

post-build:
	PAPERCONF=${WRKDIR}/papersize PATH=${WRKSRC}/src:$${PATH} ${SH} \
	    ${WRKSRC}/src/paperconfig -p ${PAPERSIZE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/papersize ${DESTDIR}${EGDIR}/papersize

.include "../../mk/bsd.pkg.mk"
