# $NetBSD: Makefile,v 1.5 2000/09/09 14:58:49 wiz Exp $
#

DISTNAME=	global-3.55
CATEGORIES=	devel
MASTER_SITES=   http://www.tamacom.com/unix/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.tamacom.com/global/

USE_PERL5=	yes
MANCOMPRESSED_IF_MANZ=	yes

LDFLAGS+=	-L../libutil
MAKE_ENV+=      LIBDIR="${PREFIX}/lib"
MAKE_ENV+=      MANDIR="${PREFIX}/man"
MAKE_ENV+=      LINTLIBDIR="${PREFIX}/libdata/lint"
MAKE_ENV+=      BINDIR="${PREFIX}/bin"

pre-install:
	@if [ ! -d ${PREFIX}/libdata/lint ];then ${MKDIR} ${PREFIX}/libdata/lint;fi

.include "../../mk/bsd.pkg.mk"
