# $NetBSD: Makefile,v 1.3 1999/08/24 12:24:30 hwr Exp $
#

DISTNAME=	global-3.42
CATEGORIES=	devel
MASTER_SITES=   http://wafu.netgate.net/tama/unix/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.tamacom.com/global/

PERL5=		yes

LDFLAGS+=	-L../lib
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	@if [ ! -d ${PREFIX}/libdata/lint ];then ${MKDIR} ${PREFIX}/libdata/lint;fi

.include "../../mk/bsd.pkg.mk"
