# $NetBSD: Makefile,v 1.20 2005/03/24 21:12:50 wiz Exp $

DISTNAME=       ha0999
PKGNAME=        ha-0.999b
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	The HA archiver using the HSC compression method

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

MAKEFILE=       makefile.nix
BUILD_TARGET=     ha
USE_GNU_TOOLS+=	make

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
