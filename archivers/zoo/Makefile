# $NetBSD: Makefile,v 1.38 2016/03/09 21:20:51 tnn Exp $

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

SUBST_CLASSES+=		fix-deps
SUBST_STAGE.fix-deps=	pre-build
SUBST_MESSAGE.fix-deps=	remove system headers from dependency list
SUBST_FILES.fix-deps=	makefile
SUBST_SED.fix-deps=	-e 's,/usr/include/[a-z/]*\.h,,g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# without this installing ploughs on case-insensitive fses
post-extract:
	cd ${WRKSRC} && mv Install Install.txt

.include "../../mk/bsd.pkg.mk"
