# $NetBSD: Makefile,v 1.16 2026/08/04 20:28:50 wiz Exp $
#

DISTNAME=	libbegemot-1.11
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/

MAINTAINER=	packages@grumpf.hope-2000.org
COMMENT=	Base development library, contains useful routines

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CFLAGS.SunOS=	-Du_int64_t=uint64_t

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
