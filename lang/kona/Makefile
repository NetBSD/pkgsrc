# $NetBSD: Makefile,v 1.2 2026/08/04 20:29:02 wiz Exp $

DISTNAME=	kona-0.0.0.2021.12.25
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=kevinlawler/}
GITHUB_PROJECT=	kona
GITHUB_TAG=	Win64-20211225

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kevinlawler/kona/
COMMENT=	Interpreter of K, an APL-like programming language
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS=	gmake

INSTALLATION_DIRS=	bin
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
