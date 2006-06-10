# $NetBSD: Makefile,v 1.25 2006/06/10 17:18:48 adrianp Exp $

DISTNAME=       zoo-2.10pl1
PKGNAME=	zoo-2.10.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate archives of files in compressed form

LICENSE=	zoo-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

BUILD_TARGET=     bsdansi
MAKEFILE=       makefile

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.pkg.mk"
