# $NetBSD: Makefile,v 1.28 2008/03/02 03:48:36 jlam Exp $

DISTNAME=	ha0999
PKGNAME=	ha-0.999b
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The HA archiver using the HSC compression method

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

MAKE_FILE=	makefile.nix
BUILD_TARGET=	ha
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
