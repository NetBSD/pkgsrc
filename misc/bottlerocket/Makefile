# $NetBSD: Makefile,v 1.18 2026/08/04 20:29:08 wiz Exp $

DISTNAME=	bottlerocket-0.04c
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://mlug.missouri.edu/~tymm/
MASTER_SITES=	http://www.linuxha.com/bottlerocket/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.linuxha.com/bottlerocket/
COMMENT=	Home Automation Software for the X10 FireCracker kit

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BUILD_TARGET=	br

X10_PORT?=		${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ARGS+=	--with-x10port=${X10_PORT:Q}
BUILD_DEFS+=		X10_PORT

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
