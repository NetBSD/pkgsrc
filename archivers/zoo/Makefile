# $NetBSD: Makefile,v 1.31 2009/02/11 14:23:31 joerg Exp $

DISTNAME=	zoo-2.10pl1
PKGNAME=	zoo-2.10.1
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate archives of files in compressed form

LICENSE=	zoo-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

BUILD_TARGET=	bsdansi
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
