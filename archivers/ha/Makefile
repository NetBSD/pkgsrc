# $NetBSD: Makefile,v 1.31 2013/09/18 20:58:35 asau Exp $

DISTNAME=	ha0999
PKGNAME=	ha-0.999b
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	# ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The HA archiver using the HSC compression method

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

MAKE_FILE=	makefile.nix
BUILD_TARGET=	ha

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
