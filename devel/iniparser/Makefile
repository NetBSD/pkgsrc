# $NetBSD: Makefile,v 1.2 2026/08/04 20:28:50 wiz Exp $

DISTNAME=	iniparser-3.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/iniparser/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ndevilla.free.fr/iniparser/
COMMENT=	Free stand-alone ini file parsing library
LICENSE=	mit

WRKSRC=	${WRKDIR}/iniparser

USE_LIBTOOL=	yes

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
