# $NetBSD: Makefile,v 1.9 2001/11/28 05:20:47 jlam Exp $
#

DISTNAME=	global-4.0.1
CATEGORIES=	devel
MASTER_SITES=   http://www.tamacom.com/global/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.tamacom.com/global/
COMMENT=	Source code tag system including web browser output

USE_BUILDLINK_ONLY=	YES
MANCOMPRESSED_IF_MANZ=	YES
GNU_CONFIGURE=		YES

LDFLAGS+=	-L../libutil
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/lint

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
