# $NetBSD: Makefile,v 1.17 2004/05/13 02:07:47 cjs Exp $
#

DISTNAME=	global-4.7
CATEGORIES=	devel
MASTER_SITES=   http://www.tamacom.com/global/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.tamacom.com/global/
COMMENT=	Source code tag system including web browser output

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
INFO_FILES=		global.info

LDFLAGS+=	-L../libutil
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/lint

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
