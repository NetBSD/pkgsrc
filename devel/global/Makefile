# $NetBSD: Makefile,v 1.8 2001/02/25 04:17:41 hubertf Exp $
#

DISTNAME=	global-4.0.1
CATEGORIES=	devel
MASTER_SITES=   http://www.tamacom.com/global/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.tamacom.com/global/
COMMENT=	Source code tag system including web browser output

USE_PERL5=	yes
MANCOMPRESSED_IF_MANZ=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L../libutil
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	@if [ ! -d ${PREFIX}/libdata/lint ];then ${INSTALL_DATA_DIR} ${PREFIX}/libdata/lint;fi

.include "../../mk/bsd.pkg.mk"
