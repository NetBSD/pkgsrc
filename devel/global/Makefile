# $NetBSD: Makefile,v 1.1 1999/01/09 04:17:00 abs Exp $
#

DISTNAME=	global-3.42
CATEGORIES=	devel
MASTER_SITES=   http://wafu.netgate.net/tama/unix/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://wafu.netgate.net/tama/unix/global.html

PERL5=		yes

LDFLAGS+=	-L../lib
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	@if [ ! -d ${PREFIX}/libdata/lint ];then mkdir ${PREFIX}/libdata/lint;fi

.include "../../mk/bsd.pkg.mk"
