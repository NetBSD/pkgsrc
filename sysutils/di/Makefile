# $NetBSD: Makefile,v 1.5 2018/02/02 10:10:34 jperkin Exp $

DISTNAME=	di-4.44
CATEGORIES=	sysutils
MASTER_SITES=	https://gentoo.com/di/

MAINTAINER=	brad.lanam.di@gmail.com
HOMEPAGE=	https://gentoo.com/di/
COMMENT=	Alternative df command
LICENSE=	zlib

USE_LANGUAGES=	c
USE_TOOLS+=	msgfmt
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=	prefix=${PREFIX} \
		LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		INSTALL_DIR=${DESTDIR}${PREFIX} \
		INST_LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale \
		DI_MANINSTDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

# Leave pkgsrc to handle security features.
MAKE_ENV+=	NO_PIE=yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
