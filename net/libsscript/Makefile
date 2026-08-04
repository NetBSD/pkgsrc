# $NetBSD: Makefile,v 1.14 2026/08/04 20:29:11 wiz Exp $

DISTNAME=	sscript-lib2.0
PKGNAME=	libsscript-2.0
PKGREVISION=	1
CATEGORIES=	net devel
#MASTER_SITES=	http://www.linuxave.net/~drow/SocketScript/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.linuxave.net/~drow/SocketScript/
COMMENT=	Simple library for creating network oriented software in C

NO_CONFIGURE=	YES
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	include/libsscript lib share/doc/libsscript

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
