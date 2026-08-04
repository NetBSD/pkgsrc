# $NetBSD: Makefile,v 1.5 2026/08/04 20:29:09 wiz Exp $
#

DISTNAME=	libquantum-1.0.0
CATEGORIES=	misc
MASTER_SITES=	http://www.libquantum.de/files/

MAINTAINER=	lennart@augustsson.net
HOMEPAGE=	http://www.libquantum.de/
COMMENT=	Quantum computing simulation library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALL_TARGET=	install quobtools_install

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
