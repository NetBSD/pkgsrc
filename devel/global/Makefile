# $NetBSD: Makefile,v 1.22 2006/03/30 03:44:43 jlam Exp $
#

DISTNAME=	global-4.8
CATEGORIES=	devel
MASTER_SITES=   http://www.tamacom.com/global/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tamacom.com/global/
COMMENT=	Source code tag system including web browser output

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run
INFO_FILES=		# PLIST

LDFLAGS+=	-L../libutil
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/lint

.include "../../mk/bsd.pkg.mk"
