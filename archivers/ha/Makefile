# $NetBSD: Makefile,v 1.32 2014/10/09 14:05:51 wiz Exp $

DISTNAME=	ha0999
PKGNAME=	ha-0.999b
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	# ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The HA archiver using the HSC compression method

WRKSRC=		${WRKDIR}

MAKE_FILE=	makefile.nix
BUILD_TARGET=	ha

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
