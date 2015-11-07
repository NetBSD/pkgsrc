# $NetBSD: Makefile,v 1.37 2015/11/07 19:20:16 dholland Exp $

DISTNAME=	zoo-2.10pl1
PKGNAME=	zoo-2.10.1
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	# ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate archives of files in compressed form
LICENSE=	zoo-license

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

BUILD_TARGET=	bsdansi
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# without this installing ploughs on case-insensitive fses
post-extract:
	cd ${WRKSRC} && mv Install Install.txt

.include "../../mk/bsd.pkg.mk"
