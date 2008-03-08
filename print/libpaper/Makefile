# $NetBSD: Makefile,v 1.3 2008/03/08 14:20:12 tnn Exp $
#

DISTNAME=	libpaper_1.1.23
PKGNAME=	${DISTNAME:S/_/-/}
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
FILES_SUBST+=		PAPERSIZE=${PAPERSIZE}

.include "../../mk/bsd.pkg.mk"
