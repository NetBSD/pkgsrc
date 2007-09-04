# $NetBSD: Makefile,v 1.1.1.1 2007/09/04 20:10:12 drochner Exp $
#

DISTNAME=	libpaper_1.1.22
PKGNAME=	libpaper-1.1.22
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/libp/libpaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/libs/libpaper1
COMMENT=	Paper size handling library

WRKSRC=		${WRKDIR}/libpaper-1.1.22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
FILES_SUBST+=	PAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
